//
// Created by Rorie Reyes on 12/18/22.
//

#include "ShieldUpdateComponent.h"
#include "WorldState.h"

void ShieldUpdateComponent::update(float fps) {

    // Update the collider
    m_RCC->setOrMoveCollider(m_TC->getLocation().x,m_TC->getLocation().y,m_TC->getSize().x,
                             m_TC->getSize().y);

}