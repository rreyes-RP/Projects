/*
 * Created by Rorie Reyes on 10/24/22.
 */

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds) {
    /*
     * Will delete and replace
     */
    if (m_NewLevelRequired) {
        /*
         * Spawn Thomas and Bob
         */

        // Call spawn once

        loadLevel(); // Load a level
    }
    if (m_Playing) {
        /*
         * Will probably delete and replace
         */
        m_Thomas.update(dtAsSeconds); // update Thomas

        m_Bob.update(dtAsSeconds); // update Bob

        /*
         * Detect collisions and see if characters
         * have reached the goal tile
         * The second part of the if condition is only executed
         * when Thomas is touching the home tile
         */
        if (detectCollisions(m_Thomas) && detectCollisions(m_Bob)) {
            m_NewLevelRequired = true; // New level required

            // Play reach goal sound
        }
        else {
            detectCollisions(m_Bob); // Run Bob's collision detection
        }

        /*
         * Let Bob and Thomas jump on each other's heads
         */
        if (m_Bob.getFeet().intersects(m_Thomas.getHead())) {
            m_Bob.stopFalling(m_Thomas.getHead().top);
        }
        else if (m_Thomas.getFeet().intersects(m_Bob.getHead())) {
            m_Thomas.stopFalling(m_Bob.getHead().top);
        }

        m_TimeRemaining -= dtAsSeconds; // Count down the time the player has left

        if (m_TimeRemaining <= 0) { // Have Thomas and Bob run out of time
            m_NewLevelRequired = true;
        }
    } // End if playing

    vector<Vector2f>::iterator it; // Check if a fire sound needs to be played

    /*
     * Iterate through the vector of Vector2f objects
     */
    for (it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++) {
        /*
         * Where is this emitter?
         * Store the location in pos
         */
        float posX = (*it).x;
        float posY = (*it).y;

        /*
         * Is the emitter near the player?
         * Make a 500 pixel rectangle around the emitter
         */
        FloatRect localRect(posX - 250, posY - 250, 500, 500);

        /*
         * Is the player inside the localRect
         */
        if (m_Thomas.getPosition().intersects(localRect)) {
            m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());
        }
    }

    /*
     * Set the appropriate view around the appropriate character
     */
    if (m_SplitScreen) {
        m_LeftView.setCenter(m_Thomas.getCenter());
        m_RightView.setCenter(m_Bob.getCenter());
    }
    else {
        if (m_Character1) {
            m_MainView.setCenter(m_Thomas.getCenter());
        }
        else {
            m_MainView.setCenter(m_Bob.getCenter());
        }
    }

    /*
     * Time to update the HUD
     * Increment the number of frames since the last HUD Calculation
     */
    m_FramesSinceLastHUDUpdate++;

    /*
     * Update the HUD every m_TargetFramesPerHUDUpdate frames
     */
    if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate) {
        /*
         * Update game HUD text
         */
        stringstream ssTime;
        stringstream ssLevel;

        /*
         * Update teh time text
         */
        ssTime << (int)m_TimeRemaining;
        m_Hud.setTime(ssTime.str());

        /*
         * Update the level text
         */
        ssLevel << "Level: " << m_LM.getCurrentLevel();
        m_Hud.setLevel(ssLevel.str());
        m_FramesSinceLastHUDUpdate = 0;
    }

    /*
     * Update the particles
     */
    if (m_PS.running()) {
        m_PS.update(dtAsSeconds);
    }
}// End of update function