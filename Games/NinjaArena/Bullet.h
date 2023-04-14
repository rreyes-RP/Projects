/*
 * Created by Rorie Reyes on 10/4/22.
 */

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet {
public:
    // Bullet Constructor
    Bullet();

    // Stop the Bullet
    void stop();

    // Returns the value of m_InFlight
    bool isInFlight();

    // Launch a new bullet in the direction of the crosshairs
    void shoot(float startX, float startY, float xTarget, float yTarget);

    // Launch a new bullet to the right of the crosshairs
    void rightShoot(float startX, float startY, float xTarget, float yTarget);

    // Location of the Bullet
    FloatRect getPosition();

    // Return the actual shape
    RectangleShape getShape();

    // Update the bullet each frame
    void update(float elapsedTime);


private:
    // Where is the bullet?
    Vector2f m_Position;

    // Bullet Shape
    RectangleShape m_BulletShape;

    // Bullet Shot
    bool m_InFlight = false;

    // Speed of Bullet
    float m_BulletSpeed = 1000;

    /*
     * Bullet speed in 1 pixel
     * Horizontally or vertically?
     */

    float m_BulletDistanceX;
    float m_BulletDistanceY;

    // Bullet boundaries
    float m_MaxX;
    float m_MinX;
    float m_MaxY;
    float m_MinY;
};
