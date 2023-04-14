/*
 * Created by Rorie Reyes on 10/16/22.
 * Header for file for the enemy's
 * pickup upgrades
 */

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class EnemyPickup {
public:

    EnemyPickup(int type);

    void setArena(IntRect arena); // Prepare a new pickup

    void spawn();

    FloatRect getPosition(); // Check the position of a pickup

    Sprite getSprite(); // Get the sprite for drawing

    void update(float elapsedTime); // Let the pickup update itself each frame

    bool isSpawned(); // Pickup spawned

    int gotIt(); // Get the goodness from the pickup

    void upgrade(); // Upgrade the value of each pickup


private:
    /*
     * Start value of health pickups for enemies
     */
    const int HEALTH_START_VALUE = 1;
    const int START_WAIT_TIME = 10;
    const int START_SECONDS_TO_LIVE = 5;

    Sprite m_Sprite; // the sprite that represents this pickup

    IntRect m_Arena; // The arena it exists in

    /*
     * Pick up worth
     * 1 = health
     */
    int m_Value;

    int m_Type;

    /*
     * Handle spawning and disappearing
     */
    bool m_Spawned;
    float m_SecondsSinceSpawn;
    float m_SecondsSinceDeSpawn;
    float m_SecondsToLive;
    float m_SecondsToWait;

};

