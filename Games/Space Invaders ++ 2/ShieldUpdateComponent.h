//
// Created by Rorie Reyes on 12/18/22.
//

#pragma once
#include "UpdateComponent.h"
#include "TransformComponent.h"
#include "GameObjectSharer.h"
#include "RectColliderComponent.h"
#include "GameObject.h"

class ShieldUpdateComponent : public UpdateComponent {
public:
    /****************************************************
	*****************************************************
	From Component interface base class
	*****************************************************
	*****************************************************/

    string getSpecificType() {
        return m_SpecificType;
    }

    void start(GameObjectSharer* gos, GameObject* self) {
        m_TC = static_pointer_cast<TransformComponent>(self->
                getComponentByTypeAndSpecificType(
                "transform", "transform"));

        m_RCC = static_pointer_cast<RectColliderComponent>(self->
                getComponentByTypeAndSpecificType(
                "collider", "rect"));
    }

    /****************************************************
	*****************************************************
	From UpdateComponent
	*****************************************************
	*****************************************************/

    void update(float fps) override;

private:
    string m_SpecificType = "shield";

    shared_ptr<TransformComponent> m_TC;
    shared_ptr<RectColliderComponent> m_RCC;

};
