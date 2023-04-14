//
// Created by Rorie Reyes on 10/27/22.
//

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter {

protected:
    Sprite m_Sprite;

    float m_JumpDuration; // Length of time to jump

    /*
     * Jumping or falling
     */
    bool m_IsJumping;
    bool m_IsFalling;

    /*
     * Direction of player
     */
    bool m_LeftPressed;
    bool m_RightPressed;

    float m_TimeThisJump; // How long does the jump last for

    bool m_JustJumped = false;

public:
    void spawn(Vector2f startPosition, float gravity);

    bool virtual handleInput() = 0; // This is a pure virtual function

    FloatRect getPosition();

    /*
     * Rectangle representing the position
     * of different parts of the sprite
     */
    FloatRect getFeet();
    FloatRect getHead();
    FloatRect getRight();
    FloatRect getLeft();

    Sprite getSprite(); // Send a copy of the sprite to main

    /*
     * Make the character stand firm
     */
    void stopFalling(float position);
    void stopRight (float position);
    void stopLeft(float position);
    void stopJump();

    Vector2f getCenter();

    void update(float elapsedTime);

private:
    float m_Gravity;

    float m_Speed = 400;

    Vector2f m_Position;

    /*
     * Characters' body parts
     */
    FloatRect m_Feet;
    FloatRect m_Head;
    FloatRect m_Right;
    FloatRect m_Left;

    Texture m_Texture;

};

