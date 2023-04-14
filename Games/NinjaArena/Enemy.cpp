/*
 * Created by Rorie Reyes on 10/3/22.
 */

#include "Enemy.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

/*
 * Spawning an enemy
 */
void Enemy::spawn(float startX, float startY, int type, int seed) {
    switch (type) {
        case 0:
            m_Sprite = Sprite(TextureHolder::GetTexture("graphics/red_ninja.png"));

            m_Speed = RED_NINJA_SPEED;
            m_Health = RED_NINJA_HEALTH;
            break;

        case 1:
            m_Sprite = Sprite(TextureHolder::GetTexture("graphics/green_ninja.png"));

            m_Speed = GREEN_NINJA_SPEED;
            m_Health = GREEN_NINJA_HEALTH;
            break;

        case 2:
            m_Sprite = Sprite(TextureHolder::GetTexture("graphics/blue_ninja.png"));

            m_Speed = BLUE_NINJA_SPEED;
            m_Health = BLUE_NINJA_HEALTH;
            break;
    }

    srand((int)time(0) * seed); // Modify the speed to make the enemies unique

    float modifier = (rand() % MAX_VARIANCE) + OFFSET; // Between 80 and 100

    modifier /= 100; // Express this as a fraction of 1
    m_Speed *= modifier;

    /*
     * Initialize its location
     */
    m_Position.x = startX;
    m_Position.y = startY;

    m_Sprite.setOrigin(25,25); // Set origin to its center


    m_Sprite.setPosition(m_Position); // Set zombie position
}

/*
 * Enemy hit
 */
bool Enemy::hit() {
    m_Health--;

    if (m_Health < 0) { // dead
        m_Alive = false;
        m_Sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));

        return true;
    }

    return false; // injured but not dead
}

/*
 * Getter functions
 */
bool Enemy::isAlive() {
    return m_Alive;
}

FloatRect Enemy::getPosition() {
    return m_Sprite.getGlobalBounds();
}

Sprite Enemy::getSprite() {
    return m_Sprite;
}

/*
 * Update function
 */
void Enemy::update(float elapsedTime, Vector2f playerLocation) {
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;

    // Update the zombie position variables
    if (playerX > m_Position.x) {
        m_Position.x = m_Position.x + m_Speed * elapsedTime;
    }

    if (playerY > m_Position.y) {
        m_Position.y = m_Position.y + m_Speed * elapsedTime;
    }

    if (playerX < m_Position.x) {
        m_Position.x = m_Position.x - m_Speed * elapsedTime;
    }

    if (playerY < m_Position.y) {
        m_Position.y = m_Position.y - m_Speed * elapsedTime;
    }

    // Move the sprite
    m_Sprite.setPosition(m_Position);

    // Face the sprite in the correct direction
    float angle = (atan2(playerY - m_Position.y, playerX - m_Position.x) * 180) / 3.141;

    m_Sprite.setRotation(angle);
}

/*
 * Healing the enemy
 */
void Enemy::increaseHealthLevel(int amount) {
    m_Health += amount;

    // But not beyond the max
    if (m_Health > m_MaxHealth) {
        m_Health = m_MaxHealth;
    }
}