#include "Engine.h"

/**
 * Rorie Reyes
 * CMPT 414N
 * Professor Johnson
 * 11/25/22
 *
 * Game Project #3: Thomas Was Late
 * Move Thomas: W,A,D,Space (Jump, Left, Right, Double Jump)
 * Move Bob: Up, Left, Right Arrows (Jump, Left, Right)
 * Quit: Escape
 *
 * Discretionary Changes:
 * b) New Hazards (5): Upward, Left, and Right Spikes
 * c) New Levels (5): Total levels with Prescribed changes = 8 Levels
 * e) New Abilities (10): Thomas can double jump with W + Space
 * f) Narrator (10): I narrated each level to give a story for the game
 * @return
 */

int main()
{
    Engine engine; // Declare instance of Engine

    engine.run(); // Start the engine

    return 0; // Quit in the usual way when the engine is stopped
}
