/**
 * Game #1: Timber Clone - Pokemon Themed
 * Professor Johnson
 * Rorie Paul Reyes
 * CMPT 414
 * Discretionary Changes:
 * a) Player moves up and down
 * b) Three Positions - Left, Center, Right
 * c) Ambient object Beedrill moves vertically
 * e) Dynamic Difficulty - Branches appear less
 *    frequent when player dies 5x
 *
 *  Controls:
 *  Start/Pause Game - enter
 *  Exit Game - escape
 *  Left - left arrow
 *  Right - right arrow
 *  Middle - space
 *  Up - up arrow
 */

#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Make code easier to type with "using namespace"
using namespace sf;

// Function declaration
void updateBranches(int seed);

void updatePineco(int pine);

// Global variable declaration

const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];

const int NUM_PINECO = 6;
Sprite pineco[NUM_PINECO];

int fainted = 0;

// Where is the player/branch?
// Left or Right
enum class side {LEFT, RIGHT, MIDDLE, UP, NONE};
side branchPositions[NUM_BRANCHES];
side pinecoPosition[NUM_PINECO];

// this is where our game starts from
int main() {
    // Create a video mode object
    VideoMode vm(1920, 1080);

    // Create and open a window for the game
    RenderWindow window(vm, "Timber!!!", Style::Default);

    // Create a texture to hold a graphic on the GPU
    Texture textureBackground;

    // Load a graphic into the texture
    textureBackground.loadFromFile("graphics/pokemon.png");

    // Create a sprite
    Sprite spriteBackground;

    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);

    // Set the spriteBackground to cover the screen
    spriteBackground.setPosition(0, 0);

    // Make a tree sprite
    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    // Prepare Beedrill
    Texture textureBeedrill;
    textureBeedrill.loadFromFile("graphics/beedrill.png");
    Sprite spriteBeedrill;
    spriteBeedrill.setTexture(textureBeedrill);
    spriteBeedrill.setPosition(800, 0);

    // Is Beedrill currently moving
    bool beedrillActive = false;

    // How fast can Beedrill fly
    float beedrillSpeed = 0.0f;

    // Make 3 cloud sprites from 1 texture
    Texture textureCloud;

    // Load 1 new texture
    textureCloud.loadFromFile("graphics/cloud.png");

    // 3 New sprites with the same texture
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    // Position the clouds on the left of the screen
    // at different heights
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    // Are the clouds currently on screen
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    // How fast is each cloud
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    // Variables to control time itself
    Clock clock;

    // Time bar
    RectangleShape timeBar;
    float timeBarStartWidth = 400;
    float timeBarHeight = 80;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    // Track whether the game is running
    bool paused = true;

    // Score
    int score = 0;

    Text messageText;
    Text scoreText;

    // Faint
    //int fainted = 0;

    Text faintText;

    // We need to choose a font
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    // Set the font to our score and faint
    messageText.setFont(font);
    scoreText.setFont(font);

    faintText.setFont(font);

    // Assign the actual message
    messageText.setString("Press Enter to start!");
    scoreText.setString("Score = 0");
    faintText.setString("Death = 0");

    // Make it really big
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);
    faintText.setCharacterSize(100);

    // Choose a color
    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);
    faintText.setFillColor(Color::Red);

    // Position the text
    FloatRect textRect = messageText.getLocalBounds();

    messageText.setOrigin(textRect.left +
                          textRect.width / 2.0f,
                          textRect.top +
                          textRect.height / 2.0f);

    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

    scoreText.setPosition(20, 20);
    faintText.setPosition(1300,20);

    // Prepare 6 branches
    Texture textureBranch;
    textureBranch.loadFromFile("graphics/branch.png");

    // Set the texture for each branch sprite
    for (int i = 0; i < NUM_BRANCHES; i++) {
        branches[i].setTexture(textureBranch);
        branches[i].setPosition(-2000, -2000);

        // Set the sprite's origin to dead centre
        // We can then spin it round without changing its position
        branches[i].setOrigin(220, 20);
    }

    // Prepare 6 pinecoes
    Texture texturePineco;
    texturePineco.loadFromFile("graphics/pineco.png");

    // Set the texture for each pineco sprite
    for (int i = 0; i < NUM_PINECO; i++) {
        pineco[i].setTexture(texturePineco);
        pineco[i].setPosition(-2000, -2000);

        // Set pineco's origin to dead center
        pineco[i].setOrigin(220,20);
    }

    // Prepare the player
    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/scyther.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(580,720);

    // The player starts on the left
    side playerSide = side::LEFT;

    // Prepare the pokeball
    Texture texturePokeball;
    texturePokeball.loadFromFile("graphics/pokeball.png");
    Sprite spritePokeball;
    spritePokeball.setTexture(texturePokeball);
    spritePokeball.setPosition(600, 870);

    // Prepare the slash animation
    Texture textureSlash;
    textureSlash.loadFromFile("graphics/slash.png");
    Sprite spriteSlash;
    spriteSlash.setTexture(textureSlash);
    spriteSlash.setPosition(700, 830);

    // Line the slash up with the tree
    const float SLASH_POSITION_LEFT = 700;
    const float SLASH_POSITION_MIDDLE = 888;
    const float SLASH_POSITION_RIGHT = 1075;

    // Prepare the flying log
    Texture textureLog;
    textureLog.loadFromFile("graphics/log.png");
    Sprite spriteLog;
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(810, 720);

    // Some other useful log related variables
    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;

    // Control the player input
    bool acceptInput = false;

    // Prepare the sounds
    // Scyther's cutting sound
    SoundBuffer cutBuffer;
    cutBuffer.loadFromFile("sound/cut.wav");
    Sound cut;
    cut.setBuffer(cutBuffer);

    // Scyther fainted under a branch
    SoundBuffer faintBuffer;
    faintBuffer.loadFromFile("sound/scyther_cry.wav");
    Sound faint;
    faint.setBuffer(faintBuffer);

    // Out of time
    SoundBuffer ootBuffer;
    ootBuffer.loadFromFile("sound/out_of_time.wav");
    Sound outOfTime;
    outOfTime.setBuffer(ootBuffer);

    // Gameplay
    while (window.isOpen()) {

        //Event event{};

        /*
         * **************************
         * Handle the players input
         * **************************
         */

        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::KeyReleased && !paused) {
                // Listen for key presses again
                acceptInput = true;

                // hide the slash animation
                spriteSlash.setPosition(2000,spriteSlash.getPosition().y);
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        // Start the game
        if (Keyboard::isKeyPressed(Keyboard::Return)) {
            paused = false;

            // Reset the time and the score
            score = 0;
            timeRemaining = 6;

            // Make all the branches disappear
            // starting in the second position
            for (int i = 1; i < NUM_BRANCHES; i++) {
                branchPositions[i] = side::NONE;
            }

            // Make all pineco disappear starting in the second position
            for (int i = 1; i < NUM_PINECO; i++) {
                pinecoPosition[i] = side::NONE;
            }

            // Make sure the pokeball is hidden
            spritePokeball.setPosition(675, 2000);

            // Move the player into position
            spritePlayer.setPosition(580, 720);

            acceptInput = true;
        }

        // Wrap the player controls to
        // Make sure we are accepting input
        if (acceptInput) {

            // First handle pressing the right cursor key
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                // Make sure the player is on the right
                playerSide = side::RIGHT;
                score++;

                // Add to the amount of time remaining
                timeRemaining += (2 / score) + 0.15;

                spriteSlash.setPosition(SLASH_POSITION_RIGHT,
                                      spriteSlash.getPosition().y);

                spritePlayer.setPosition(1200, 720);

                // Update the branches
                updateBranches(score);

                // update pineco
                updatePineco(score);

                // Set the log flying to the left
                spriteLog.setPosition(810, 720);
                logSpeedX = -5000;
                logActive = true;

                acceptInput = false;

                // Play a cut sound
                cut.play();
            }

            // Handle the left cursor key
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                // Make sure the player is on the left
                playerSide = side::LEFT;

                score++;

                // Add to the amount of time remaining
                timeRemaining += (2 / score) + 0.15;

                spriteSlash.setPosition(SLASH_POSITION_LEFT,
                                      spriteSlash.getPosition().y);

                spritePlayer.setPosition(580, 720);

                // update the branches
                updateBranches(score);

                // update pineco
                updatePineco(score);

                // set the log flying
                spriteLog.setPosition(810, 720);
                logSpeedX = 5000;
                logActive = true;

                acceptInput = false;

                // Play a cut sound
                cut.play();
            }

            // Handle the space cursor key
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                // Make sure the player is in the middle
                playerSide = side::MIDDLE;

                score++;

                // Add the amount of time remaining
                timeRemaining += (2 / score) + 0.15;

                spriteSlash.setPosition(SLASH_POSITION_MIDDLE,
                                        spriteSlash.getPosition().y);

                spritePlayer.setPosition(890, 720);

                // update the branches
                updateBranches(score);

                // update pineco
                updatePineco(score);

                acceptInput = false;

                // Play a cut sound
                cut.play();
            }

            // Handle the up cursor key
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                // Make sure the player is in the middle
                playerSide = side::UP;

                score++;

                // Add the amount of time remaining
                timeRemaining += (2 / score) + 0.15;

                spriteSlash.setPosition(SLASH_POSITION_MIDDLE,
                                        spriteSlash.getPosition().y);

                spritePlayer.setPosition(890, 500);

                // update the branches
                updateBranches(score);

                // update pineco
                updatePineco(score);

                acceptInput = false;

                // Play a cut sound
                cut.play();
            }

        }

        /*
         * **************************
         * Update the scene
         * **************************
         */

        if (!paused) {

            // Measure time
            Time dt = clock.restart();

            // Subtract from the amount of time remaining
            timeRemaining -= dt.asSeconds();
            // size up the time bar
            timeBar.setSize(Vector2f(timeBarWidthPerSecond *
                                     timeRemaining, timeBarHeight));

            if (timeRemaining <= 0.0f) {

                // Pause the game
                paused = true;

                // Change the message shown to the player
                messageText.setString("Out of time!!");

                // Reposition the text based on its new size
                FloatRect textRect = messageText.getLocalBounds();
                messageText.setOrigin(textRect.left +
                                      textRect.width / 2.0f,
                                      textRect.top +
                                      textRect.height / 2.0f);

                messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

                // Play the out of time sound
                outOfTime.play();
            }

            // Set Beedrill
            if (!beedrillActive) {

                // How fast is the bee
                srand((int) time(0));
                beedrillSpeed = (rand() % 200) + 200;

                // How high is the bee
                srand((int) time(0) * 10);
                float plane = (rand() % 500) + 500;
                spriteBeedrill.setPosition(plane, 1080);
                beedrillActive = true;

            } else {
                // Move Beedrill
                spriteBeedrill.setPosition(
                        spriteBeedrill.getPosition().x,
                        spriteBeedrill.getPosition().y - (beedrillSpeed * dt.asSeconds()));

                // Has the bee reached the left-hand edge of the screen
                if (spriteBeedrill.getPosition().y < -100) {
                    // Set it up ready to be a whole Beedrill next frame
                    beedrillActive = false;
                }
            }

            // Manage the clouds
            // Cloud 1
            if (!cloud1Active) {
                // How fast is the cloud
                srand((int) time(0) * 10);
                cloud1Speed = (rand() % 200);

                // How high is the cloud
                srand((int) time(0) * 10);
                float height = (rand() % 150);
                spriteCloud1.setPosition(-200, height);
                cloud1Active = true;
            } else {
                spriteCloud1.setPosition(
                        spriteCloud1.getPosition().x +
                        (cloud1Speed * dt.asSeconds()),
                        spriteCloud1.getPosition().y);

                // Has the cloud reached the right hand edge of the screen
                if (spriteCloud1.getPosition().x > 1920) {
                    // Set it up ready to be a whole new cloud next frame
                    cloud1Active = false;
                }
            }

            // Cloud 2
            if (!cloud2Active) {
                // How fast is the cloud
                srand((int) time(0) * 20);
                cloud2Speed = (rand() % 200);

                // How high is the cloud
                srand((int) time(0) * 20);
                float height = (rand() % 300) - 150;
                spriteCloud2.setPosition(-200, height);
                cloud2Active = true;
            } else {
                spriteCloud2.setPosition(
                        spriteCloud2.getPosition().x +
                        (cloud2Speed * dt.asSeconds()),
                        spriteCloud2.getPosition().y);

                // Has the cloud reached the right hand edge of the screen
                if (spriteCloud2.getPosition().x > 1920) {
                    // Set it up ready to be a whole new cloud next frame
                    cloud2Active = false;
                }
            }

            // Cloud 3
            if (!cloud3Active) {
                // How fast is the cloud
                srand((int) time(0) * 30);
                cloud3Speed = (rand() % 200);

                // How high is the cloud
                srand((int) time(0) * 30);
                float height = (rand() % 450) - 150;
                spriteCloud3.setPosition(-200, height);
                cloud3Active = true;
            } else {
                spriteCloud3.setPosition(
                        spriteCloud3.getPosition().x +
                        (cloud3Speed * dt.asSeconds()),
                        spriteCloud3.getPosition().y);

                // Has the cloud reached the right hand edge of the screen
                if (spriteCloud3.getPosition().x > 1920) {
                    // Set it up ready to be a whole new cloud next frame
                    cloud3Active = false;
                }
            }

            // Update the score text
            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());

            // update the branch sprites
            for (int i = 0; i < NUM_BRANCHES; i++) {
                float height = i * 150;

                if (branchPositions[i] == side::LEFT) {
                    // Move the sprite to the left side
                    branches[i].setPosition(610, height);

                    // Flip the sprite round the other way
                    branches[i].setRotation(180);
                }

                else if (branchPositions[i] == side::RIGHT) {
                    // Move the sprite to the right side
                    branches[i].setPosition(1330, height);

                    // Set the sprite rotation to normal
                    branches[i].setRotation(0);
                }

                else {
                    // Hide the branch
                    branches[i].setPosition(3000, height);
                }
            }

            // Update pineco sprite
            for (int i = 0; i < NUM_PINECO; i++) {
                float height = i * 150;

                if (pinecoPosition[i] == side::MIDDLE) {
                    // Move the sprite to the middle
                    pineco[i].setPosition(1150, height);
                }

                else if (pinecoPosition[i] == side::UP) {
                    // Move the sprite up
                    pineco[i].setPosition(1150,height);
                }

                else {
                    // Hide pineco
                    pineco[i].setPosition(3000, height);
                }
            }

            // Handle a flying log
            if (logActive) {

                spriteLog.setPosition(
                        spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
                        spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()));

                // Has the log reached the right hand edge?
                if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000) {
                    // Set it up ready to be a whole new log next fram
                    logActive = false;
                    spriteLog.setPosition(810, 600);
                }
            }

            // Did Scyther faint by a branch or pineco?
            if (branchPositions[5] == playerSide) {
                // faint
                paused = true;
                acceptInput = false;

                // Draw the pokeball
                spritePokeball.setPosition(600, 870);

                // hide the player
                spritePlayer.setPosition(2000, 660);

                // Change the text of the message
                messageText.setString("SCYTHER fainted!!");

                // Center it on the screen
                FloatRect textRect = messageText.getLocalBounds();

                messageText.setOrigin(textRect.left +
                textRect.width / 2.0f,
                textRect.top + textRect.height / 2.0f);

                messageText.setPosition(1920 / 2.0f,1080 / 2.0f);

                // Play the faint sound
                faint.play();

                fainted++;

            }

            else if (pinecoPosition[5] == playerSide) {
                // faint
                paused = true;
                acceptInput = false;

                // Draw the pokeball
                spritePokeball.setPosition(600, 870);

                // hide the player
                spritePlayer.setPosition(2000, 660);

                // Change the text of the message
                messageText.setString("SCYTHER fainted!!");

                // Center it on the screen
                FloatRect textRect = messageText.getLocalBounds();

                messageText.setOrigin(textRect.left +
                                      textRect.width / 2.0f,
                                      textRect.top + textRect.height / 2.0f);

                messageText.setPosition(1920 / 2.0f,1080 / 2.0f);

                // Play the faint sound
                faint.play();

                fainted++;
            }

            // Update the faint text
            std::stringstream ff;
            ff << "Faint = " << fainted;
            faintText.setString(ff.str());


        } // End if (!paused)

        /*
         * **************************
         * Draw the scene
         * **************************
         */

        // Clear everything from the last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);

        // Draw the clouds
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        // Draw branches
        for (int i = 0; i < NUM_BRANCHES; i++) {
            window.draw(branches[i]);
        }

        // Draw the tree
        window.draw(spriteTree);

        // Draw pinecoes
        for (int i = 0; i < NUM_PINECO; i++) {
            window.draw(pineco[i]);
        }

        // Draw the chopped log
        window.draw(spriteLog);

        // Draw the player
        window.draw(spritePlayer);

        // Draw the slash animation
        window.draw(spriteSlash);

        // Draw the pokeball
        window.draw(spritePokeball);

        // Draw the insect
        window.draw(spriteBeedrill);

        // Draw the score
        window.draw(scoreText);

        // Draw the faint
        window.draw(faintText);

        // Draw the timebar
        window.draw(timeBar);

        if (paused) {
            // Draw our message
            window.draw(messageText);
        }

        // Show everything we just drew
        window.display();

    }

    return 0;
}

// Function definition
void updateBranches(int seed) {
    // Move all the branches down one place
    for (int j = NUM_BRANCHES - 1; j > 0; j--) {
        branchPositions[j] = branchPositions[j - 1];
    }

    // Spawn a new branch at position 0
    // LEFT, RIGHT, or NONE
    srand((int)time(0) + seed);
    //int r =(rand() % 5);
    int r = 0;

    if (fainted < 5) {

        r = (rand() % 5);

        switch (r) {
            case 0:
                branchPositions[0] = side::LEFT;
                break;

            case 1:
                branchPositions[0] = side::RIGHT;
                break;

            default:
                branchPositions[0] = side::NONE;
                break;
        }
    }

    else {
        r = (rand() % 10);

        switch (r) {
            case 0:
                branchPositions[0] = side::LEFT;
                break;

            case 1:
                branchPositions[0] = side::RIGHT;
                break;

            default:
                branchPositions[0] = side::NONE;
                break;
        }
    }

}

void updatePineco(int pine) {
    // Move all the pinecos down one place
    for (int j = NUM_PINECO - 1; j > 0; j--) {
        pinecoPosition[j] = pinecoPosition[j - 1];
    }

    // Spawn a new pineco at position 0 in the MIDDLE
    srand((int)time(0) + pine);
    int r = (rand() % 5);

    switch (r) {
        case 0:
            pinecoPosition[0] = side::MIDDLE;
            break;

        case 1:
            pinecoPosition[0] = side::UP;
            break;

        default:
            pinecoPosition[0] = side::NONE;
            break;
    }
}