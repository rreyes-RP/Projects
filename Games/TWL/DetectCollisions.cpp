//
// Created by Rorie Reyes on 11/6/22.
//

#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter &character) {
    bool reachedGoal = false;

    FloatRect detectionZone = character.getPosition();

    FloatRect block; // Test each block

    block.width = TILE_SIZE;
    block.height = TILE_SIZE;

    /*
     * Build a zone around Thomas to detect collisions
     */
    int startX = (int) (detectionZone.left / TILE_SIZE) - 1;
    int startY = (int) (detectionZone.top / TILE_SIZE) - 1;
    int endX = (int) (detectionZone.left / TILE_SIZE) + 2;

    int endY = (int) (detectionZone.top / TILE_SIZE) + 3; // Check tiles vertically due to Thomas's height

    /*
     * Make sure we don't test positions lower than zero
     * or higher than the end of the array
     */
    if (startX < 0) {
        startX = 0;
    }

    if (startY < 0) {
        startY = 0;
    }

    if (endX >= m_LM.getLevelSize().x) {
        endX = m_LM.getLevelSize().x;
    }

    if (endY >= m_LM.getLevelSize().y) {
        endY = m_LM.getLevelSize().y;
    }

    /*
     * Has the character fallen out of the map
     */
    FloatRect level(0, 0,
                    m_LM.getLevelSize().x * TILE_SIZE,
                    m_LM.getLevelSize().y * TILE_SIZE);

    if (!character.getPosition().intersects(level)) {
        character.spawn(m_LM.getStartPosition(), GRAVITY); // respawn the character
    }

    for (int x = startX; x < endX; x++) {
        for (int y = startY; y < endY; y++) {
            /*
             * Initialize the starting position of the current block
             */
            block.left = x * TILE_SIZE;
            block.top = y * TILE_SIZE;

            /*
             * Play the different sounds of each tile type
             */

            /*
             * Fire
             */
            if (m_ArrayLevel[y][x] == 2) {
                if (m_Bob.getHead().intersects(block)) {
                    m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);
                    m_SM.playFallInFire();
                }

                if (m_Thomas.getFeet().intersects(block)) {
                    m_Thomas.stopFalling(block.top);
                }
            }

            /*
             * Water
             */
            if (m_ArrayLevel[y][x] == 3 || m_ArrayLevel[y][x] == 9) {
                if (m_Thomas.getHead().intersects(block)) {
                    m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
                    m_SM.playFallInWater();
                }

                if (m_ArrayLevel[y][x] == 9) {
                    if (m_Bob.getFeet().intersects(block)) {
                        m_Bob.stopFalling(block.top);
                    }
                }
            }

            /*
             * Upward Spikes
             */
            if (m_ArrayLevel[y][x] == 5) {
                if (character.getFeet().intersects(block)) {
                    character.spawn(m_LM.getStartPosition(), GRAVITY);
                    m_SM.playFallOnSpikes();
                }
            }

            /*
             * Left Spikes
             */
            if (m_ArrayLevel[y][x] == 6) {
                if (character.getRight().intersects(block)) {
                    character.spawn(m_LM.getStartPosition(), GRAVITY);
                    m_SM.playFallOnSpikes();
                }
            }

            /*
             * Right Spike
            */
            if (m_ArrayLevel[y][x] == 7) {
                if (character.getLeft().intersects(block)) {
                    character.spawn(m_LM.getStartPosition(), GRAVITY);
                    m_SM.playFallOnSpikes();
                }
            }

            /*
             * Character colliding with a regular block
             */
            if (m_ArrayLevel[y][x] == 1 || m_ArrayLevel[y][x] == 8) {
                if (character.getRight().intersects(block)) {
                    character.stopRight(block.left);
                }
                else if (character.getLeft().intersects(block)) {
                    character.stopLeft(block.left);
                }

                if (character.getFeet().intersects(block)) {
                    character.stopFalling(block.top);
                }
                else if (character.getHead().intersects(block)) {
                    character.stopJump();
                }
            }

            /*
             * Particle collision after touching hazards
             */
            if (!m_PS.running()) {
                if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3 || m_ArrayLevel[y][x] == 5 ||
                m_ArrayLevel[y][x] == 6 || m_ArrayLevel[y][x] == 7 || m_ArrayLevel[y][x] == 9 ) {
                    if (character.getFeet().intersects(block)) {
                        m_PS.emitParticles(character.getCenter()); // position and start the particle system
                    }
                }
            }

            /*
             * Has the character reached the goal
             */
            if (m_ArrayLevel[y][x] == 4) {
                if (m_Thomas.getFeet().intersects(block) && m_Bob.getFeet().intersects(block)) {
                    reachedGoal = true; // Character reached goal
                    m_SM.playReachGoal();
                }
            }
        }
    }
    return reachedGoal;

}
