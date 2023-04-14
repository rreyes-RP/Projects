#include "Paddle.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {

    enum class State {LOST, GAME_OVER, MENU, PLAYING}; // State of play
    State state = State::MENU; // Initial state is the menu screen*/

    // Get the screen resolution and create an SFML Window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window (VideoMode(resolution.x, resolution.y),
                         "Ping Pong", Style::Default);

    int score = 0;
    int lives = 1;
    float speed = 500.f;

    //bool paused = true; // Track whether the game is running

    // Create an SFML view for the main function
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));

    // Create a paddle at the right center of the screen
    Paddle paddle(1920 * 1.75, 1080 );

    // Create Ball
    Ball ball(0,  1080 * 1.5);

    // Create a Text object called HUD
    Text hud;

    // Font for text
    Font font;
    font.loadFromFile("fonts/DS-DIGI.ttf");

    // Set the font
    hud.setFont(font);

    // Font size
    hud.setCharacterSize(75);

    // Font color
    hud.setFillColor(Color::White);

    hud.setPosition(20,20);

    /*
     * Menu
     */
    Sprite spriteMenu; // Menu background
    Texture textureMenu;
    textureMenu.loadFromFile("graphics/pong_bg.png");
    spriteMenu.setTexture(textureMenu);
    spriteMenu.setPosition(1000,500);

    Text menuText;
    menuText.setFont(font);
    menuText.setCharacterSize(155);
    menuText.setFillColor(Color::White);
    menuText.setPosition(400,400);
    menuText.setString("Press Enter to Play");

    /*
     * Game Over
     */
    Sprite spriteGameOver; // Game over background
    Texture textureGameOver;
    textureGameOver.loadFromFile("graphics/game_over_bg.png");
    spriteGameOver.setTexture(textureGameOver);
    spriteGameOver.setPosition(1000,500);


    // Control the player input
    bool acceptInput = false;

    // Clock for timing
    Clock clock;

    while (window.isOpen()) {
        /*
         * Handle the player input
         */
        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::KeyReleased) {
                // Listen for key presses again
                acceptInput = true;

            }

        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        // Start the game
        if (event.key.code == Keyboard::Return && state == State::MENU ||
            event.key.code == Keyboard::Return && state == State::GAME_OVER) {
            state = State::PLAYING;
            //paused = false;
            score = 0;
            lives = 1;

            clock.restart(); // Reset the clock to prevent a fame jump
        }

        // Wrap the player controls to make sure we are accepting input
        if (state == State::PLAYING) {
            if (acceptInput) {
                // Handle the pressing and releasing of the arrow keys
                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    paddle.moveUp();
                    acceptInput = false;
                } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
                    paddle.moveDown();
                    acceptInput = false;
                } else if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    paddle.moveLeft();
                    acceptInput = false;
                } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    paddle.moveRight();
                    acceptInput = false;
                } else {
                    paddle.stop();
                    acceptInput = true;
                }

            }
        }


        /*
         * Update the paddle, the ball, and HUD
         */

        if (state == State::PLAYING && lives >= 1) {
            // Update the delta time
            Time dt = clock.restart();

            paddle.update(dt);
            ball.update(dt);

            // Update the HUD text
            std::stringstream ss;
            ss << "Score:" << score << " Lives:" << lives;
            hud.setString(ss.str());

            // Handle ball hitting the right side
            if (ball.getPosition().left > window.getSize().x) {
                // reverse the ball direction
                ball.reboundRightSide();

                // Remove a life
                lives--;

                /*
                // Check for zero lives
                if (lives < 1) {
                    state = State::GAME_OVER;

                    // reset ball speed
                    ball.resetSpeed(speed);
                }*/
            }

            // Handle Ball hitting left side
            if (ball.getPosition().left < 0) {
                ball.reboundPaddleOrLeftSides();

                // Add a point
                score++;
            }

            // Handle ball hitting top or bottom
            if (ball.getPosition().top < 0 || ball.getPosition().top + ball.getPosition().height > window.getSize().y) {
                ball.reboundTopAndBottom();
            }

            // Has the ball hit the bat
            if (ball.getPosition().intersects(paddle.getPosition())) {
                // Hit detected
                ball.reboundPaddleOrLeftSides();

                // Add a point
                score++;
            }
        }

        else if (state == State::PLAYING && lives < 1) {
            state = State::GAME_OVER;

            // reset ball speed
            ball.resetSpeed(speed);
        }
        /*
         * Draw the paddle, ball, and HUD
         */

        if (state == State::PLAYING) {

            window.clear();

            window.draw(hud);

            window.draw(paddle.getSprite());

            window.draw(ball.getSprite());
        }

        if (state == State::MENU) {
            window.draw(spriteMenu);
            window.draw(menuText);
        }

        if (state == State::GAME_OVER) {
            window.draw(spriteGameOver);
            window.draw(menuText);
        }

        window.display();
    }

    return 0;
}
