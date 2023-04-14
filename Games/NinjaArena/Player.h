/*
 * Created by Rorie Reyes on 9/25/22
 * Header file for player
 */

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
public:
    Player();

    void spawn (IntRect arena, Vector2f resolution, int tileSize);

    void resetPlayerStats(); // Call at the end of every game

    bool hit(Time timeHit); // Player getting hit by an enemy

    Time getLastHitTime(); // Last time player was hit

    FloatRect getPosition(); // Where is the player

    Vector2f getCenter(); // Center of the player

    float getRotation(); // Angle the player is facing


    Sprite getSprite(); // Copy of the sprite

    /*
     * Move the player
     */
    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    /*
     * Stop the player
     */
    void stopLeft();

    void stopRight();

    void stopUp();

    void stopDown();

    void update(float elapsedTime, Vector2i mousePosition); // Call once every frame

    void upgradeSpeed(); // Player speed boost

    void upgradeHealth(); // Player health boost

    void increaseHealthLevel (int amount); // Replenish player health

    int getHealth(); // Current Player health

    void increaseShieldLevel(int amount); // Replenish player shield

    int getShield (); // Current shield health for player

private:
    const float START_SPEED = 200;
    const float START_HEALTH = 100;
    const float START_SHIELD = 50;

    Vector2f m_Position; // Player position

    Sprite m_Sprite; // Player Sprite

    Texture m_Texture; // Player texture

    Vector2f m_Resolution; // Screen Resolution for the Player

    IntRect m_Arena; // Current size of the Arena

    int m_TileSize; // Tile size of the arena

    /*
     *  Directions of the player moving
     */
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;

    int m_Health; // Health of the player

    int m_MaxHealth; // Max Health of the player

    int m_Shield; // Shield health of the player

    int m_MaxShield; // Max Shield of the player

    Time m_LastHit; // Last time player was hit

    float m_Speed; // Speed in pixels per second

};
