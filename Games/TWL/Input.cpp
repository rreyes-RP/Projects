/*
 * Created by Rorie Reyes on 10/24/22.
 */

#include "Engine.h"

void Engine::input() {
    Event event;
    while(m_Window.pollEvent(event)) {
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) { // Handle the player quitting
                m_Window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Return)) { // Handle the player starting the game
                m_Playing = true;
            }

            if (Keyboard::isKeyPressed(Keyboard::Q)) { // Switch between Thomas and Bob
                m_Character1 = !m_Character1;
            }

            if (Keyboard::isKeyPressed(Keyboard::E)) { // Switch between full and split-screen
                m_SplitScreen = !m_SplitScreen;
            }
        }
    }

    /*
     * Thomas's input
     */
    if (m_Thomas.handleInput()) {
        m_SM.playJump(); // Play a jump sound
    }

    /*
     * Bob's input
     */
    if (m_Bob.handleInput()) {
        m_SM.playJump(); // Play a jump sound
    }
}
