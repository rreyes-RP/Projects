/*
 * Created by Rorie Reyes on 10/3/22.
 * Header file for enemies
 */

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy {
public:
    bool hit(); // Handle when a star hits an enemy

    bool isAlive(); // Is the enemy still alive?

    void spawn(float startX, float startY, int type, int seed); // Spawn a new enemy

    FloatRect getPosition(); // Return a rectangle that is the position in the world

    Sprite getSprite(); // Get a copy of the sprite to draw

    void increaseHealthLevel(int amount); // Increase health level for bad ninjas

    void update(float elapsedTime, Vector2f playerLocation); // Update the enemy each frame

private:
    /*
     * Speed of zombie type
     */
    const float RED_NINJA_SPEED = 40;
    const float GREEN_NINJA_SPEED = 80;
    const float BLUE_NINJA_SPEED = 20;

    /*
     * Strength of each enemy type
     */
    const float RED_NINJA_HEALTH = 5;
    const float GREEN_NINJA_HEALTH = 1;
    const float BLUE_NINJA_HEALTH = 3;

    /*
     * Vary enemy ninja speed
     */
    const int MAX_VARIANCE = 30;
    const int OFFSET = 101 - MAX_VARIANCE;

    Vector2f m_Position; // Enemy location

    Sprite m_Sprite; // Enemy sprite

    float m_Speed; // Declaring enemy speed

    float m_Health; // Declaring enemy health

    float m_MaxHealth; // Max health for enemies

    bool m_Alive; // Alive or not
};