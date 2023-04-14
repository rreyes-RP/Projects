//
// Created by Rorie Reyes on 12/18/22.
//

#pragma once
#include "UpdateComponent.h"
#include "TransformComponent.h"
#include "GameObjectSharer.h"
#include "RectColliderComponent.h"
#include "GameObject.h"

class BulletSpawner;

class UfoUpdateComponent : public UpdateComponent {
public:
    void reverse();
    bool UfoIsMovingRight();

    /****************************************************
	*****************************************************
	From Component interface base class
	*****************************************************
	*****************************************************/

    string getSpecificType() {
        return m_SpecificType;
    }

    void start(GameObjectSharer* gos, GameObject* self) {

        /*
         * Where is the player?
         */
        m_PlayerTC = static_pointer_cast<TransformComponent>(gos->findFirstObjectWithTag("Player")
                                                                     .getComponentByTypeAndSpecificType("transform", "transform"));

        m_PlayerRCC = static_pointer_cast<RectColliderComponent>(gos->findFirstObjectWithTag("Player")
                                                                         .getComponentByTypeAndSpecificType("collider", "rect"));

        /*
         * Where is this specific invader
         */
        m_TC = static_pointer_cast<TransformComponent>(self->getComponentByTypeAndSpecificType(
                "transform", "transform"));

        m_RCC = static_pointer_cast<RectColliderComponent>(self->getComponentByTypeAndSpecificType(
                "collider", "rect"));
    }

    /****************************************************
    *****************************************************
    From UpdateComponent
    *****************************************************
    *****************************************************/

    void update(float fps) override;

private:
    string m_SpecificType = "ufo";

    shared_ptr<TransformComponent> m_TC;
    shared_ptr<RectColliderComponent> m_RCC;
    shared_ptr<TransformComponent> m_PlayerTC;
    shared_ptr<RectColliderComponent> m_PlayerRCC;

    float m_Speed = 15.0f;
    bool m_MovingRight = true;
    float m_AccuracyModifier;

};
