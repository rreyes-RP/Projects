/*
 * Created by Rorie Reyes on 9/29/22.
 */

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle {
public:

    Paddle (float startX, float startY);

    enum class movePaddle {UP, DOWN, RIGHT, LEFT, NONE};

    FloatRect getPosition();

    // Copy of the sprite to the main function
    Sprite getSprite();

    // Move the paddle
    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void stop();

    void update (Time dt);

private:

    movePaddle padMove = movePaddle::NONE;

    // Paddle position
    Vector2f m_Position;

    // Paddle Sprite
    Sprite m_Sprite;

    // Paddle Texture
    Texture  m_Texture;

    float m_Speed = 1000.0f;

};

