/*
 * Created by Rorie Reyes on 10/13/22.
 */

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
public:
    Ball (float startX, float startY);

    FloatRect getPosition();

    Sprite getSprite();

    float getYVelocity();

    void reboundTopAndBottom();

    void reboundPaddleOrLeftSides();

    void reboundRightSide();

    void update(Time dt);

    void resetSpeed(float speed);

private:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;

    float m_Speed = 1000.0f;
    float m_DirectionX = 0.2f;
    float m_DirectionY = 0.2f;

};
