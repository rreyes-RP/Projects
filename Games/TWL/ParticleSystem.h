//
// Created by Rorie Reyes on 11/25/22.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"

using namespace sf;
using namespace std;

class ParticleSystem : public Drawable {
public:
    virtual void draw(RenderTarget& target, RenderStates states) const;

    void init(int count);

    void emitParticles(Vector2f position);

    void update(float elapsed);

    bool running();

private:
    vector<Particle> m_Particles;
    VertexArray m_Vertices;
    float m_Duration;
    bool m_IsRunning = false;
};
