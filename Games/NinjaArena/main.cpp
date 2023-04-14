#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "NinjaArena.h"
#include "TextureHolder.h"
#include "Bullet.h"
#include "Pickup.h"
#include "EnemyPickup.h"

/*
 * Rorie Paul Reyes
 * CMPT_414N
 * Professor Johnson
 * 10/17/22
 *
 * Game Project #2: Ninja Arena
 * Zombie Arena Clone
 * Move player: WASD
 * Throw Stars: Left Click
 * Pause: Enter
 * Quit: Escape
 *
 * Discreationary changes:
 * b) New Player Upgrade/ f) Your Own Idea: Created a shield for the player to protect it's current health
 * c) Enemy Behavior: Enemies have their own pickup item to heal themselves. Player cannot collide with this pickup
 * d) Multi-Shot Weapon: Player throws two stars at the same time -> one through the middle, the other to the side. Two
 * "bullets" will be lost in the clip
 * e) Arena Shape: Set up arena to represent a rectangle is expanded appropriately per level
 */

using namespace sf;

int main() {

    TextureHolder holder;

    enum class State {PAUSED, LEVELING_UP, GAME_OVER, PLAYING}; // Four states of the game

    State state = State::GAME_OVER; // Initial state is game over

    Vector2f resolution; // Get the screen resolution and create an SFML Window
    resolution.x = VideoMode::getDesktopMode().width;

    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window (VideoMode(resolution.x, resolution.y),
                         "Enemy Arena", Style::Default);

    // Create an SFML view for the main function
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));

    Clock clock; // Clock for timing

    Time gameTimeTotal; // Length of active PLAYING state

    Vector2f mouseWorldPosition; // Where is the mouse within the world coordinates

    Vector2i mouseScreenPosition; // Where is the mouse within the screen coordinates

    Player player; // Instance of the Player class

    IntRect arena; // Boundaries of the arena

    VertexArray background; // Create the background

    //Texture textureBackground; // Load the texture for our background vertex array
    //textureBackground.loadFromFile("graphics/hardwood.png");
    Texture textureBackground = TextureHolder::GetTexture("graphics/hardwood.png");

    /*
     * Prepare for a wave of enemies
     */
    int numNinjas;
    int numNinjasAlive;
    Enemy* enemy = nullptr;

    Bullet bullets[100]; // 100 bullets total
    int currentBullet = 0;
    int bulletsSpare = 96;
    int bulletsInClip = 24;
    int clipSize = 24;
    float fireRate = 1;
    Time lastPressed; // last time fire button was pressed


    window.setMouseCursorVisible(true); // Hide the mouse pointer and replace with crosshair
    Sprite spriteCrosshair;
    Texture textureCrosshair = TextureHolder::GetTexture("graphics/crosshair.png");

    spriteCrosshair.setTexture(textureCrosshair);
    spriteCrosshair.setOrigin(25,25);

    Pickup healthPickup(1); // Create pickups
    Pickup ammoPickup(2);
    Pickup shieldPickup(3);
    EnemyPickup enemyHealthPickup(4);


    /*
     * Initial score at the start of the game
     */
    int score = 0;
    int hiScore = 0;

    Sprite spriteGameOver; // Home/game over screen
    Texture textureGameOver = TextureHolder::GetTexture("graphics/ninja_background.png");
    spriteGameOver.setTexture(textureGameOver);
    spriteGameOver.setPosition(0,0);

    View hudView(FloatRect(0,0,resolution.x,resolution.y)); // View for HUD

    Sprite spriteAmmoIcon; // Sprite for ammo icon
    Texture textureAmmoIcon = TextureHolder::GetTexture("graphics/ammo_icon.png");
    spriteAmmoIcon.setTexture(textureAmmoIcon);
    spriteAmmoIcon.setPosition(20,980);

    Font font; // Load the font
    font.loadFromFile("fonts/ninjutsuBB.ttf");

    Text pausedText; // Paused
    pausedText.setFont(font);
    pausedText.setCharacterSize(155);
    pausedText.setFillColor(Color::White);
    pausedText.setPosition(400,400);
    pausedText.setString("Press Enter \nto continue");

    Text gameOverText; // Game over
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(125);
    gameOverText.setFillColor(Color::White);
    gameOverText.setPosition(250, 850);
    gameOverText.setString("Press Enter to play");

    Text levelUpText; // Leveling up
    levelUpText.setFont(font);
    levelUpText.setCharacterSize(80);
    levelUpText.setFillColor(Color::White);
    levelUpText.setPosition(150, 250);
    std::stringstream levelUpStream;
    levelUpStream <<
        "1- Increased rate of fire" <<
        "\n2- Increased clip size(next reload)" <<
        "\n3- Increased max health" <<
        "\n4- Increased run speed" <<
        "\n5- More and better health pickups" <<
        "\n6- More and better ammo pickups";
    levelUpText.setString(levelUpStream.str());

    Text ammoText; // Ammo
    ammoText.setFont(font);
    ammoText.setCharacterSize(55);
    ammoText.setFillColor(Color::White);
    ammoText.setPosition(200,980);

    Text scoreText; // Score
    scoreText.setFont(font);
    scoreText.setCharacterSize(55);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(20, 0);
    
    std::ifstream inputFile("gamedata/scores.txt"); // Load the high score from a text file
    if (inputFile.is_open()) {
        // >> Reads the data
        inputFile >> hiScore;
        inputFile.close();
    }
    
    Text hiScoreText; // Hi Score
    hiScoreText.setFont(font);
    hiScoreText.setCharacterSize(55);
    hiScoreText.setFillColor(Color::White);
    hiScoreText.setPosition(1400,0);
    std::stringstream s;
    s << "Hi Score:" << hiScore;
    hiScoreText.setString(s.str());
    
    Text enemyRemainingText; // enemy remaining
    enemyRemainingText.setFont(font);
    enemyRemainingText.setCharacterSize(55);
    enemyRemainingText.setFillColor(Color::White);
    enemyRemainingText.setPosition(1500,980);
    enemyRemainingText.setString("enemy: 100");

    // Wave number
    int wave = 0;
    Text waveNumberText;
    waveNumberText.setFont(font);
    waveNumberText.setCharacterSize(55);
    waveNumberText.setFillColor(Color::White);
    waveNumberText.setPosition(1250,980);
    waveNumberText.setString("Wave: 100");

    // Health Bar
    RectangleShape healthBar;
    healthBar.setFillColor(Color::Red);
    healthBar.setPosition(450, 980);

    // Shield Bar
    RectangleShape shieldBar;
    shieldBar.setFillColor(Color::Blue);
    shieldBar.setPosition(450, 950);

    // Debug HUD
    Text debugText;
    debugText.setFont(font);
    debugText.setCharacterSize(25);
    debugText.setFillColor(Color::White);
    debugText.setPosition(20,220);
    std::ostringstream ss;

    // When did we last update the HUD
    int framesSinceLastHUDUpdate = 0;

    // How often (in frames) should we update the HUD
    int fpsMeasurementFrameInterval = 1000;

    /*
     * Sound
     */

    // Prepare the hit sound
    SoundBuffer hitBuffer;
    hitBuffer.loadFromFile("sound/hurt.wav");
    Sound hit;
    hit.setBuffer(hitBuffer);

    // Prepare the stab sound when other ninjas are hit
    SoundBuffer splatBuffer;
    splatBuffer.loadFromFile("sound/stab.wav");
    Sound splat;
    splat.setBuffer(splatBuffer);

    // Prepare the ninja star throw sound
    SoundBuffer shootBuffer;
    shootBuffer.loadFromFile("sound/star_throw.wav");
    Sound shoot;
    shoot.setBuffer(shootBuffer);

    // Prepare star pickup and reload sound
    SoundBuffer reloadBuffer;
    reloadBuffer.loadFromFile("sound/star.wav");
    Sound reload;
    reload.setBuffer(reloadBuffer);

    // Prepare the failed sound
    SoundBuffer reloadFailedBuffer;
    reloadFailedBuffer.loadFromFile("sound/reload_failed.wav");
    Sound reloadFailed;
    reloadFailed.setBuffer(reloadFailedBuffer);

    // Prepare the gong sound for power ups
    SoundBuffer powerupBuffer;
    powerupBuffer.loadFromFile("sound/gong.wav");
    Sound powerup;
    powerup.setBuffer(powerupBuffer);

    // Prepare the healing pickup sound
    SoundBuffer pickupBuffer;
    pickupBuffer.loadFromFile("sound/healing.wav");
    Sound pickup;
    pickup.setBuffer(pickupBuffer);

    // Preare the healing pickup sound for the enemy
    SoundBuffer enemyPickupBuffer;
    enemyPickupBuffer.loadFromFile("sound/enemy_heal.wav");
    Sound enemyPickup;
    enemyPickup.setBuffer(enemyPickupBuffer);

    // Prepare the shield pickup sound
    SoundBuffer shieldBuffer;
    shieldBuffer.loadFromFile("sound/shield.wav");
    Sound shield;
    shield.setBuffer(shieldBuffer);

    // Wave Number

    // Main Game loop
    while (window.isOpen()) {
        /*
         * **************
         * Handle Input
         * **************
         */

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyPressed) {
                // Pause a game
                if (event.key.code == Keyboard::Return && state == State::PLAYING) {
                    state = State::PAUSED;
                }

                // Restart while paused
                else if (event.key.code == Keyboard::Return && state == State::PAUSED) {
                    state = State::PLAYING;
                    // Reset the clock so there isn't a frame jump
                    clock.restart();
                }

                // Start a new game while in GAME_OVER state
                else if (event.key.code == Keyboard::Return && state == State::GAME_OVER) {
                    state = State::LEVELING_UP;
                    wave = 0;
                    score = 0;

                    // Prepare the gun and ammo for next game
                    currentBullet = 0;
                    bulletsSpare = 96;
                    bulletsInClip = 24;
                    clipSize = 24;
                    fireRate = 1;

                    // Reset the player's state
                    player.resetPlayerStats();
                }

                if (state == State::PLAYING) {
                    // Reloading
                    if (event.key.code == Keyboard::R) {
                        if (bulletsSpare >= clipSize) {
                            // Reload
                            bulletsInClip = clipSize;
                            bulletsSpare -= clipSize;
                            reload.play();
                        }

                        else if (bulletsSpare > 0) {
                            // Few bullets left
                            bulletsInClip = bulletsSpare;
                            bulletsSpare = 0;
                            reload.play();
                        }

                        else {
                            // More code coming
                            reloadFailed.play();
                        }
                    }
                }
            }// End event polling

            // Handle the player quitting
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }

            // Handle WASD while playing
            if (state == State::PLAYING) {
                // Handle the pressing and releasing of thw WASD keys
                if (Keyboard::isKeyPressed(Keyboard::W)) {
                    player.moveUp();
                }
                else {
                    player.stopUp();
                }

                if (Keyboard::isKeyPressed(Keyboard::S)) {
                    player.moveDown();
                }
                else {
                    player.stopDown();
                }

                if (Keyboard::isKeyPressed(Keyboard::A)) {
                    player.moveLeft();
                }
                else {
                    player.stopLeft();
                }

                if (Keyboard::isKeyPressed(Keyboard::D)) {
                    player.moveRight();
                }
                else {
                    player.stopRight();
                }

                // Fire a bullet
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    if (gameTimeTotal.asMilliseconds() - lastPressed.asMilliseconds() >
                        1000 / fireRate && bulletsInClip > 0) {
                        /*
                         *  Pass the center of the player
                         *  and the center of the cross-hair
                         *  to the shoot function
                         */
                        bullets[currentBullet].shoot(player.getCenter().x, player.getCenter().y, mouseWorldPosition.x, mouseWorldPosition.y);
                        currentBullet++;
                        if (currentBullet > 99) {
                            currentBullet = 0;
                        }

                        bullets[currentBullet].rightShoot(player.getCenter().x, player.getCenter().y, mouseWorldPosition.x, mouseWorldPosition.y);
                        currentBullet++;
                        if (currentBullet > 99) {
                            currentBullet = 0;
                        }

                        lastPressed = gameTimeTotal;

                        shoot.play();

                        //bulletsInClip--;
                        bulletsInClip = bulletsInClip - 3;
                    }
                }// End left click fire

            }// End WASD while playing

            // Handle the LEVELING up state
            if (state == State::LEVELING_UP) {
                // Handle the player LEVELING up
                if (event.key.code == Keyboard::Num1) {
                    // Increase fire rate
                    fireRate++;
                    state = State::PLAYING;
                }

                if (event.key.code == Keyboard::Num2) {
                    // Increase clip size
                    clipSize += clipSize;
                    state = State::PLAYING;
                }

                if (event.key.code == Keyboard::Num3) {
                    // Increase health
                    player.upgradeHealth();
                    state = State::PLAYING;
                }

                if (event.key.code == Keyboard::Num4) {
                    // Increase speed
                    player.upgradeSpeed();
                    state = State::PLAYING;
                }

                if (event.key.code == Keyboard::Num5) {
                    // Upgrade health pickup
                    healthPickup.upgrade();
                    state = State::PLAYING;
                }

                if (event.key.code == Keyboard::Num6) {
                    // Upgrade ammo pickup
                    ammoPickup.upgrade();
                    state = State::PLAYING;
                }

                if (state == State::PLAYING) {

                    // Increase the wave number
                    wave++;

                    // Prepare the level
                    arena.width = 800 * wave;
                    arena.height = 500 * wave;
                    arena.left = 0;
                    arena.top = 0;

                    /*
                     * Pass the vertex array by reference
                     * to the createBackground function
                     */

                    int tileSize = createBackground(background, arena);

                    // Modify later
                    //int tileSize = 50;

                    // Spawn the player in the middle of the arena
                    player.spawn(arena, resolution, tileSize);

                    // Configure the pick-ups
                    healthPickup.setArena(arena);
                    ammoPickup.setArena(arena);
                    shieldPickup.setArena(arena);
                    enemyHealthPickup.setArena(arena);

                    // Create horde of enemy
                    numNinjas = 5 * wave;

                    // Delete the previously allocated memory
                    delete[] enemy;
                    enemy = createHorde(numNinjas, arena);
                    numNinjasAlive = numNinjas;

                    // Play the powerup sound
                    powerup.play();

                    // Reset the clock so there isn't a frame jump
                    clock.restart();
                }
            } // End LEVELING up

            /*
             * ******************
             * Updating the frame
             * ******************
             */

            if (state == State::PLAYING) {
                // Update the delta time
                Time dt = clock.restart();

                // Update the total game time
                gameTimeTotal += dt;

                // Make a decimal fraction of 1 from the delta time
                float dtAsSeconds = dt.asSeconds();

                // Where is the mouse pointer
                mouseScreenPosition = Mouse::getPosition();

                // Convert mouse position to world coordinates of mainView
                mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

                // Set the crosshair to the mouse world location
                spriteCrosshair.setPosition(mouseWorldPosition);

                // Update the player
                player.update(dtAsSeconds, Mouse::getPosition());

                // Make a note of the players new position
                Vector2f playerPosition(player.getCenter());

                // Make the view center around the player
                mainView.setCenter(player.getCenter());

                // Loop through each Enemy and update them
                for (int i = 0; i < numNinjas; i++) {
                    if (enemy[i].isAlive()) {
                        enemy[i].update(dt.asSeconds(), playerPosition);
                    }
                }

                // Update any bullets that are in-flight
                for (int i = 0; i < 100; i++) {
                    if (bullets[i].isInFlight()) {
                        bullets[i].update(dtAsSeconds);
                    }
                }

                // Update the pickups
                healthPickup.update(dtAsSeconds);
                ammoPickup.update(dtAsSeconds);
                shieldPickup.update(dtAsSeconds);
                enemyHealthPickup.update(dtAsSeconds);

                // Collision detection
                // Has the enemy been shot
                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < numNinjas; j++) {
                        if (bullets[i].isInFlight() && enemy[j].isAlive()) {
                            if (bullets[i].isInFlight() && enemy[j].isAlive()) {
                                if (bullets[i].getPosition().intersects((enemy[j].getPosition()))) {
                                    // Stop the bullet
                                    bullets[i].stop();

                                    // Register the hit and see if it was a kill
                                    if (enemy[j].hit()) {
                                        // Hit and kill
                                        score += 10;
                                        if (score >= hiScore) {
                                            hiScore = score;
                                        }

                                        numNinjasAlive--;

                                        // When all the enemy are dead
                                        if (numNinjasAlive == 0) {
                                            state = State::LEVELING_UP;
                                        }
                                    }

                                    splat.play();
                                }
                            }
                        }
                    }
                }

                // enemy touching the player
                for (int i = 0; i < numNinjas; i++) {
                    if (player.getPosition().intersects(enemy[i].getPosition()) && enemy[i].isAlive()) {

                        if (player.hit(gameTimeTotal)) {
                            // More here later
                            hit.play();
                        }

                        if (player.getHealth() <= 0) {
                            state = State::GAME_OVER;

                            std::ofstream outputFile("gamedata/scores.txt");
                            // << writes the data
                            outputFile << hiScore;
                            outputFile.close();
                        }
                    }
                } // End player touched

                // Has the player touched health pickups
                if (player.getPosition().intersects(healthPickup.getPosition()) && healthPickup.isSpawned()) {
                    player.increaseHealthLevel(healthPickup.gotIt());
                    pickup.play();
                }

                // Has the player touched the shield pickups
                if (player.getPosition().intersects(shieldPickup.getPosition()) && shieldPickup.isSpawned()) {
                    player.increaseShieldLevel(shieldPickup.gotIt());
                    shield.play();
                }

                // Has the player touched ammo pickups
                if (player.getPosition().intersects(ammoPickup.getPosition()) && ammoPickup.isSpawned()) {
                    bulletsSpare += ammoPickup.gotIt();
                    reload.play();
                }

                // Has the enemy touched their health pickup
                for (int i = 0; i < numNinjas; i++) {
                    if (enemy[i].getPosition().intersects(enemyHealthPickup.getPosition()) && enemyHealthPickup.isSpawned()) {
                        enemy[i].increaseHealthLevel(enemyHealthPickup.gotIt());
                        enemyPickup.play();
                    }
                }

                // Size of the health bar
                healthBar.setSize(Vector2f(player.getHealth() * 3, 50));

                // Size of the shield health bar
                shieldBar.setSize(Vector2f(player.getShield() * 3, 25));

                // Increment the number of frames since the previous update
                framesSinceLastHUDUpdate++;

                // re-calculate every fpsMeasurementFrameInterval frames
                if (framesSinceLastHUDUpdate > fpsMeasurementFrameInterval) {
                    // Update game HUD text
                    std::stringstream ssAmmo;
                    std::stringstream ssScore;
                    std::stringstream ssHiScore;
                    std::stringstream ssWave;
                    std::stringstream ssenemyAlive;

                    // Update the ammo text
                    ssAmmo << bulletsInClip << "/" << bulletsSpare;
                    ammoText.setString(ssAmmo.str());

                    // Update the score text
                    ssScore << "Score:" << score;
                    scoreText.setString(ssScore.str());

                    // Update the high score text
                    ssHiScore << "Hi Score:" << hiScore;
                    hiScoreText.setString(ssHiScore.str());

                    // Update the wave
                    ssWave << "Wave:" << wave;
                    waveNumberText.setString(ssWave.str());

                    // Update the high score text
                    ssenemyAlive << "enemy:" << numNinjasAlive;
                    enemyRemainingText.setString(ssenemyAlive.str());

                    framesSinceLastHUDUpdate = 0;
                } // End HUD update

            } // End updating the scene

            /*
             * ******************
             * Draw the scene
             * ******************
             */

            if (state == State::PLAYING) {
                window.clear();

                // set the mainView to be displayed in the window
                window.setView(mainView);

                // Draw the background
                window.draw(background, &textureBackground);

                // Draw the enemy
                for (int i = 0; i < numNinjas; i++) {
                    window.draw(enemy[i].getSprite());
                }

                for (int i = 0; i < 100; i++) {
                    if (bullets[i].isInFlight()) {
                        window.draw(bullets[i].getShape());
                    }
                }

                // Draw the player
                window.draw(player.getSprite());

                // Draw the pick-ups if currently spawned
                if  (ammoPickup.isSpawned()) {
                    window.draw(ammoPickup.getSprite());
                }

                if (healthPickup.isSpawned()) {
                    window.draw(healthPickup.getSprite());
                }

                if (shieldPickup.isSpawned()) {
                    window.draw(shieldPickup.getSprite());
                }

                if (enemyHealthPickup.isSpawned()) {
                    window.draw(enemyHealthPickup.getSprite());
                }

                // Draw the crosshair
                window.draw(spriteCrosshair);

                // Switch to the HUD view
                window.setView(hudView);

                // Draw all the HUD elements
                window.draw(spriteAmmoIcon);
                window.draw(ammoText);
                window.draw(scoreText);
                window.draw(hiScoreText);
                window.draw(healthBar);
                window.draw(shieldBar);
                window.draw(waveNumberText);
                window.draw(enemyRemainingText);
            }

            if (state == State::LEVELING_UP) {
                window.draw(spriteGameOver);
                window.draw(levelUpText);
            }

            if (state == State::PAUSED) {
                window.draw(pausedText);
            }

            if (state == State::GAME_OVER) {
                window.draw(spriteGameOver);
                window.draw(gameOverText);
                window.draw(scoreText);
                window.draw(hiScoreText);
            }

            window.display();
        }// End game loop

    }
    return 0;
}
