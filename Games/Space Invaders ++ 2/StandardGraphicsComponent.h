#pragma once
#include "Component.h"
#include "GraphicsComponent.h"
#include <string>

class Component;

class StandardGraphicsComponent : public GraphicsComponent {
public:

	/****************************************************
	*****************************************************
	From Component interface base class
	*****************************************************
	*****************************************************/

	string getSpecificType() {
		return m_SpecificType;
	}

	void start(
		GameObjectSharer* gos, GameObject* self) {
	}

	/****************************************************
	*****************************************************
	From GraphicsComponent
	*****************************************************
	*****************************************************/

	void draw(RenderWindow& window, shared_ptr<TransformComponent> t) override;

	void initializeGraphics(string bitmapName, Vector2f objectSize) override;

private:
    Sprite m_Sprite;
    string m_SpecificType = "standard";
};