/*
 *  Created by Rorie Reyes on 9/27/22
 *  Generating player and characteristics
 */

#include "Player.h"
#include "TextureHolder.h"
#include <cmath>

Player::Player() {
    m_Speed = START_SPEED;
    m_Health = START_HEALTH;
    m_MaxHealth = START_HEALTH;
    m_Shield = START_SHIELD;
    m_MaxShield = START_SHIELD;

    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/good_ninja.png"));

    m_Sprite.setOrigin(25,25); // Origin of the sprite to center for smooth rotation
}

/*
 * Spawning the player
 */
void Player::spawn (IntRect arena, Vector2f resolution, int tileSize) {
    // Place the player in the middle of the arena
    m_Position.x = arena.width / 2;
    m_Position.y = arena.height / 2;

    // Copy details of the arena to the player's m_Arena
    m_Arena.left = arena.left;
    m_Arena.width = arena.width;
    m_Arena.top = arena.top;
    m_Arena.height = arena.height;

    m_TileSize = tileSize; // Remember how big the tile are in theis arena

    m_Resolution.x = resolution.x; // Store the resolution for future use
    m_Resolution.y = resolution.y;
}

/*
 * Reset the player stats
 * after each round or game over
 */
void Player::resetPlayerStats() {
    m_Speed = START_SPEED;
    m_Health = START_HEALTH;
    m_MaxHealth = START_HEALTH;
}

Time Player::getLastHitTime() {
    return m_LastHit;
}

/*
 * Player getting damaged
 */
bool Player::hit(Time timeHit) {
    if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200) {
        m_LastHit = timeHit;
        if (m_Shield > 0) {
            m_Shield -= 10;
        }

        else {
            m_Health -= 10;
        }

        return true;
    }

    else {
        return false;
    }
}

FloatRect Player::getPosition() {
    return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter() {
    return m_Position;
}

float Player::getRotation() {
    return m_Sprite.getRotation();
}

Sprite Player::getSprite() {
    return m_Sprite;
}

int Player::getHealth() {
    return m_Health;
}

int Player::getShield() {
    return m_Shield;
}

void Player::moveLeft() {
    m_LeftPressed = true;
}

void Player::moveRight() {
    m_RightPressed = true;
}

void Player::moveUp() {
    m_UpPressed = true;
}

void Player::moveDown() {
    m_DownPressed = true;
}

void Player::stopLeft() {
    m_LeftPressed = false;
}

void Player::stopRight() {
    m_RightPressed = false;
}

void Player::stopUp() {
    m_UpPressed = false;
}

void Player::stopDown() {
    m_DownPressed = false;
}

/*
 * Player characteristics
 * - Speed
 * - Direction
 * - Staying inside the arena
 */
void Player::update(float elapsedTime, Vector2i mousePosition) {
    if (m_UpPressed) {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
    }

    if (m_RightPressed) {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
    }

    m_Sprite.setPosition(m_Position);

    // Keep the player in the arena
    if (m_Position.x > m_Arena.width - m_TileSize) {
        m_Position.x = m_Arena.width - m_TileSize;
    }

    if (m_Position.x < m_Arena.left + m_TileSize) {
        m_Position.x = m_Arena.left + m_TileSize;
    }

    if (m_Position.y > m_Arena.height - m_TileSize) {
        m_Position.y = m_Arena.height - m_TileSize;
    }

    if (m_Position.y < m_Arena.top + m_TileSize) {
        m_Position.y = m_Arena.top + m_TileSize;
    }

    // Calculate the angle the player is facing
    float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
                         mousePosition.x - m_Resolution.x / 2)
                                 * 180) / 3.141;

    m_Sprite.setRotation(angle);
}

/*
 * Upgrades for the player
 *  - Speed
 *  - Max Health
 *  - Increase Health
 */

/*
 * Speed
 */
void Player::upgradeSpeed() {
    m_Speed += (START_SPEED * 0.2);
}

/*
 * Upgrade Max Health
 */
void Player::upgradeHealth() {
    m_MaxHealth += (START_HEALTH * 0.2);
}

/*
 * Replenish Health
 */
void Player::increaseHealthLevel(int amount) {
    m_Health += amount;

    // But not beyond the max
    if (m_Health > m_MaxHealth) {
        m_Health = m_MaxHealth;
    }
}

/*
 * Replenish Shield
 */
void Player::increaseShieldLevel(int amount) {
    m_Shield += amount;

    // But not beyond the max
    if (m_Shield > m_MaxShield) {
        m_Health = m_MaxShield;
    }
}




