/*
 * Created by Rorie Reyes on 9/29/22.
 */

#include "Paddle.h"

/*
 * Constructor and called when
 * we create the project
 */

Paddle::Paddle (float startX, float startY) {
    m_Position.x = startX;
    m_Position.y = startY;

    // Associate a texture with the paddle sprite
    m_Texture.loadFromFile("graphics/paddle.png");
    m_Sprite.setTexture(m_Texture);

    // Position of paddle
    m_Sprite.setPosition(m_Position);

}

FloatRect Paddle::getPosition() {
    return m_Sprite.getGlobalBounds();
}

Sprite Paddle::getSprite() {
    return m_Sprite;
}

void Paddle::moveUp() {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        padMove = movePaddle::UP;
    }
}

void Paddle::moveDown() {
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        padMove = movePaddle::DOWN;
    }
}

void Paddle::moveLeft() {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        padMove = movePaddle::LEFT;
    }
}

void Paddle::moveRight() {
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        padMove = movePaddle::RIGHT;
    }
}

void Paddle::stop() {
    padMove = movePaddle::NONE;
}

void Paddle::update(Time dt) {
    if (padMove == movePaddle::UP) {
        m_Position.y -= m_Speed * dt.asSeconds();
    }

    if (padMove == movePaddle::DOWN) {
        m_Position.y += m_Speed * dt.asSeconds();
    }

    if (padMove == movePaddle::RIGHT) {
        m_Position.x += m_Speed * dt.asSeconds();
    }

    if (padMove == movePaddle::LEFT) {
        m_Position.x -= m_Speed * dt.asSeconds();
    }

    m_Sprite.setPosition(m_Position);

    // Keep the paddle within the area
    if (m_Position.x < 2200) {
        m_Position.x = 2200;
    }

    if (m_Position.x > 1920 * 1.75) {
        m_Position.x = 1920 * 1.75;
    }

    if (m_Position.y > 1900) {
        m_Position.y = 1900;
    }

    if (m_Position.y < 0) {
        m_Position.y = 0;
    }
}
