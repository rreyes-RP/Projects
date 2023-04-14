/*
 * Created by Rorie Reyes on 10/11/22
 */

#include "Pickup.h"
#include "TextureHolder.h"

/*
 * Generating the pickup items
 */
Pickup::Pickup(int type) {
    m_Type = type;

    /*
     * Associate the texture with the sprite
     */
    if (m_Type == 1) { // Health pickup
        m_Sprite = Sprite(TextureHolder::GetTexture("graphics/heart.png"));

        m_Value = HEALTH_START_VALUE; // Health pickup worth

    }

    else if (m_Type == 2) { // Ammo pickup
        m_Sprite = Sprite(TextureHolder::GetTexture("graphics/ninja_star.png"));

        m_Value = AMMO_START_VALUE; // Ammo pickup worth

    }

    else { // Shield pickup
        m_Sprite = Sprite(TextureHolder::GetTexture("graphics/shield.png"));

        m_Value = SHIELD_START_VALUE; // Shield pickup worth

    }

    m_Sprite.setOrigin(25,25);

    m_SecondsToLive = START_SECONDS_TO_LIVE;
    m_SecondsToWait = START_WAIT_TIME;
}

/*
 * Preparing the arena for spawning the pickups
 */
void Pickup::setArena(IntRect arena) {

    // Copy the details of the arena to the pickup's m_Arena
    m_Arena.left = arena.left + 50;
    m_Arena.width = arena.width - 50;
    m_Arena.top = arena.top + 50;
    m_Arena.height = arena.height - 50;

    spawn();
}

/*
 * Spawning the pickups
 */
void Pickup::spawn() {
    // Spawn at a random location
    srand((int)time(0) / m_Type);
    int x = (rand() % m_Arena.width);
    srand((int)time(0) * m_Type);
    int y = (rand() % m_Arena.height);

    m_SecondsSinceSpawn = 0;
    m_Spawned = true;

    m_Sprite.setPosition(x, y);
}

FloatRect Pickup::getPosition() {
    return m_Sprite.getGlobalBounds();
}

Sprite Pickup::getSprite() {
    return m_Sprite;
}

bool Pickup::isSpawned() {
    return m_Spawned;
}

int Pickup::gotIt() {
    m_Spawned = false;
    m_SecondsSinceDeSpawn = 0;
    return m_Value;
}

/*
 * Generating the loop of the spawned items
 */
void Pickup::update(float elapsedTime) {
    if (m_Spawned) {
        m_SecondsSinceSpawn += elapsedTime;
    }

    else {
        m_SecondsSinceDeSpawn += elapsedTime;
    }

    // Hide pickup
    if (m_SecondsSinceSpawn > m_SecondsToLive && m_Spawned) {
        // Remove the pickup and put it somewhere else
        m_Spawned = false;
        m_SecondsSinceDeSpawn = 0;
    }

    // Do we need to spawn a pickup?
    if (m_SecondsSinceDeSpawn > m_SecondsToWait && !m_Spawned) {
        // Spawn the pickup and reset timer
        spawn();
    }
}

/*
 * Values added to the characteristics
 * based on the pickups
 */
void Pickup::upgrade() {
    if (m_Type == 1) {
        m_Value += (HEALTH_START_VALUE * 0.5);
    }

    else if (m_Type == 2) {
        m_Value += (AMMO_START_VALUE * 0.5);
    }

    // Make them more frequent and last longer
    m_SecondsToLive += (START_SECONDS_TO_LIVE / 10);
    m_SecondsToWait += (START_WAIT_TIME / 10);
}
