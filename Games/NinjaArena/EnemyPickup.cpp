/*
 * Created by Rorie Reyes on 10/16/22
 */

#include "EnemyPickup.h"
#include "TextureHolder.h"

EnemyPickup::EnemyPickup(int type) {
    m_Type = type;

    /*
     * Associate the texture with the sprite
     * Enemy's health pickup
     */
    if (m_Type == 4) {
        m_Sprite = Sprite(TextureHolder::GetTexture("graphics/enemy_heart.png"));

        m_Value = HEALTH_START_VALUE; // Health pickup worth

    }

    m_Sprite.setOrigin(25,25);

    m_SecondsToLive = START_SECONDS_TO_LIVE;
    m_SecondsToWait = START_WAIT_TIME;
}

/*
 * Preparing the arena for spawning the enemy's pickups
 */
void EnemyPickup::setArena(IntRect arena) {

    /*
     * Copy the details of the arena to the pickup's m_Arena
     */
    m_Arena.left = arena.left + 50;
    m_Arena.width = arena.width - 50;
    m_Arena.top = arena.top + 50;
    m_Arena.height = arena.height - 50;

    spawn();
}

/*
 * Spawning the pickups
 */
void EnemyPickup::spawn() {
    // Spawn at a random location
    srand((int)time(0) / m_Type);
    int x = (rand() % m_Arena.width);
    srand((int)time(0) * m_Type);
    int y = (rand() % m_Arena.height);

    m_SecondsSinceSpawn = 0;
    m_Spawned = true;

    m_Sprite.setPosition(x, y);
}

FloatRect EnemyPickup::getPosition() {
    return m_Sprite.getGlobalBounds();
}

Sprite EnemyPickup::getSprite() {
    return m_Sprite;
}

bool EnemyPickup::isSpawned() {
    return m_Spawned;
}

int EnemyPickup::gotIt() {
    m_Spawned = false;
    m_SecondsSinceDeSpawn = 0;
    return m_Value;
}

/*
 * Generating the loop of the spawned items
 */
void EnemyPickup::update(float elapsedTime) {
    if (m_Spawned) {
        m_SecondsSinceSpawn += elapsedTime;
    }

    else {
        m_SecondsSinceDeSpawn += elapsedTime;
    }

    if (m_SecondsSinceSpawn > m_SecondsToLive && m_Spawned) { // Hide pickup
        m_Spawned = false; // Remove the pickup and put it somewhere else
        m_SecondsSinceDeSpawn = 0;
    }

    if (m_SecondsSinceDeSpawn > m_SecondsToWait && !m_Spawned) { // Do we need to spawn a pickup?
        // Spawn the pickup and reset timer
        spawn();
    }
}
