//
// Created by Rorie Reyes on 10/27/22.
//

#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas() {
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

    m_JumpDuration = 0.45;
}

bool Thomas::handleInput() {
    m_JustJumped = false;

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        /*
         * Start a jump if not already jumping
         * but only if standing on a block (not falling)
         */
        if (!m_IsJumping && !m_IsFalling) {
            m_IsJumping = true;
            m_TimeThisJump = 0;
            m_JustJumped = true;
        }
    }
    else {
        m_IsJumping = false;
        m_IsFalling = true;

        /*
         * Handle double jump
         */
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (!m_IsJumping && m_IsFalling) {
                m_IsJumping = true;
                m_TimeThisJump = 0;
                m_JustJumped = true;
            }
        }

        else {
            m_IsJumping = false;
            m_IsFalling = true;
        }

    }

    /*
     * Left movement
     */
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        m_LeftPressed = true;
    }

    else {
        m_LeftPressed = false;
    }

    /*
     * Right movement
     */
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        m_RightPressed = true;
    }

    else {
        m_RightPressed = false;
    }

    return m_JustJumped;
}