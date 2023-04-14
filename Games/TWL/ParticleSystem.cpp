//
// Created by Rorie Reyes on 11/25/22.
//

#include <SFML/Graphics.hpp>
#include "math.h"
#include "ParticleSystem.h"

void ParticleSystem::init(int numParticles) {
    m_Vertices.setPrimitiveType(Points);
    m_Vertices.resize(numParticles);

    /*
     * Create particles
     */
    for (int i = 0; i < numParticles; i++) {
        srand(time(0) + i);
        float angle = (rand() % 360) * 3.14f / 180.0f;
        float speed = (rand() % 600) + 600.0f;

        Vector2f direction;
        direction = Vector2f(cos(angle) * speed, sin(angle) * speed);

        m_Particles.push_back(Particle(direction));
    }
}

void ParticleSystem::update(float elapsed) {
    m_Duration -= elapsed;
    vector<Particle>::iterator i;
    int currentVertex = 0;

    for (i = m_Particles.begin(); i != m_Particles.end(); i++) {
        (*i).update(elapsed); // Move the particle

        m_Vertices[currentVertex++].position = i->getPosition(); // Update the vertex array
    }

    if (m_Duration < 0) {
        m_IsRunning = false;
    }
}

void ParticleSystem::emitParticles(sf::Vector2f position) {
    m_IsRunning = true;
    m_Duration = 2;

    int currentVertex = 0;

    for (auto it = m_Particles.begin(); it != m_Particles.end(); it++) {
        m_Vertices[currentVertex++].color = Color::Yellow;
        it->setPosition(position);
    }
}

void ParticleSystem::draw(RenderTarget& target, RenderStates states) const {
    target.draw(m_Vertices, states);
}

bool ParticleSystem::running() {
    return m_IsRunning;
}