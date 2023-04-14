//
// Created by Rorie Reyes on 12/18/22.
//

#include "UfoUpdateComponent.h"
#include "BulletSpawner.h"
#include "WorldState.h"
#include "SoundEngine.h"

void UfoUpdateComponent::update(float fps) {
    if (m_MovingRight) {
        m_TC->getLocation().x += m_Speed * fps;
    }
    else {
        m_TC->getLocation().x -= m_Speed * fps;
    }

    m_RCC->setOrMoveCollider(m_TC->getLocation().x,m_TC->getLocation().y,
                             m_TC->getSize().x, m_TC->getSize().y); // Update the collider

    /*
     * Is the UFO above the player +- world units
     */
    if ((m_TC->getLocation().x + (m_TC->getSize().x / 2)) > (m_PlayerTC->getLocation().x - m_AccuracyModifier) &&
        (m_TC->getLocation().x + (m_TC->getSize().x / 2)) < (m_PlayerTC->getLocation().x +
                                                             (m_PlayerTC->getSize().x + m_AccuracyModifier))) {
    }
}

void UfoUpdateComponent::reverse() {
    m_MovingRight = !m_MovingRight;
}

bool UfoUpdateComponent::UfoIsMovingRight() {
    return m_MovingRight;
}
