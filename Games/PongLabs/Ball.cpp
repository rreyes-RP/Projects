/*
 * Created by Rorie Reyes on 10/13/22.
 */

#include "Ball.h"

Ball::Ball(float startX, float startY) {
    m_Position.x = startX;
    m_Position.y = startY;

    m_Texture.loadFromFile("graphics/ball.png");
    m_Sprite.setTexture(m_Texture);

    // Position of paddle
    m_Sprite.setPosition(m_Position);
}

FloatRect Ball::getPosition() {
    return m_Sprite.getGlobalBounds();
}

Sprite Ball::getSprite() {
    return m_Sprite;
}

float Ball::getYVelocity() {
    return m_DirectionY;
}

void Ball::reboundTopAndBottom() {
    m_DirectionY = -m_DirectionY;
    //m_Speed = m_Speed * 0.98f;
}

void Ball::reboundPaddleOrLeftSides() {
    m_DirectionX = -m_DirectionX;
    //m_Speed = m_Speed * 1.1f;
}

void Ball::reboundRightSide() {
    m_Position.x = 0;
    m_Position.y = 1080;
    m_DirectionX = -m_DirectionX;
}

void Ball::update(Time dt) {
    // Update the Ball's position
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

    // Move the Ball
    m_Sprite.setPosition(m_Position);
}

void Ball::resetSpeed(float speed) {
    // Set speed back to original
    m_Speed = speed;
}


