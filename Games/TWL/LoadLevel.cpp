//
// Created by Rorie Reyes on 10/31/22.
//

#include "Engine.h"

void Engine::loadLevel() {
    m_Playing = false;

    /*
     * Delete the previously allocated memory
     */
    for (int i = 0; i < m_LM.getLevelSize().y; ++i) {
        delete[] m_ArrayLevel[i];
    }
    delete[] m_ArrayLevel;

    /*
     * Load the next 2D array with the map for the level
     * and repopulate the vertex array as well
     */
    m_ArrayLevel = m_LM.nextLevel(m_VALevel);

    populateEmitters(m_FireEmitters, m_ArrayLevel); // Prepare the sound emitters

    m_TimeRemaining = m_LM.getTimeLimit(); // New time limit

    /*
     * Spawn Thomas and Bob
     */
    m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
    m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);

    m_NewLevelRequired = false; // Make sure code isn't run again
}
