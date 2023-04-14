//
// Created by Rorie Reyes on 11/6/22.
//

#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(vector<sf::Vector2f> &vSoundEmitters, int **arrayLevel) {

    vSoundEmitters.empty(); // Make sure the vector is empty

    /*
     * Keep track of the previous emitter,
     * so we don't make too many
     */
    FloatRect previousEmitter;

    /*
     * Search for fire in the level
     */
    for (int x = 0; x < (int)m_LM.getLevelSize().x; x++) {

        for (int y = 0; y < (int)m_LM.getLevelSize().y; y++) {

            /*
             * Fire is present
             */
            if (arrayLevel[y][x] == 2) {

                /*
                 * Skip over any fire tiles too near a previous emitter
                 */
                if (!FloatRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE)
                .intersects(previousEmitter)) {

                    vSoundEmitters.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

                    /*
                     * Make a rectangle 6 blocks x 6 blocks,
                     * so we don't make any more emitters
                     * too close to this one
                     */
                    previousEmitter.left = x * TILE_SIZE;
                    previousEmitter.top = y * TILE_SIZE;
                    previousEmitter.width  = TILE_SIZE * 6;
                    previousEmitter.height = TILE_SIZE * 6;
                }
            }
        }
    }
    return;
}