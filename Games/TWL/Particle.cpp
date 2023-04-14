//
// Created by Rorie Reyes on 11/25/22.
//

#include "Particle.h"

/*
 * Determine the direction
 */
Particle::Particle(sf::Vector2f direction) {
    m_Velocity.x = direction.x;
    m_Velocity.y = direction.y;
}

/*
 * Move the particle
 */
void Particle::update(float dt) {
    m_Position += m_Velocity * dt;
}

void Particle::setPosition(sf::Vector2f position) {
    m_Position = position;
}

Vector2f Particle::getPosition() {
    return m_Position;
}