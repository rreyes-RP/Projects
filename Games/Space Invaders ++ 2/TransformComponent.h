#pragma once
#include "Component.h"
#include<SFML/Graphics.hpp>

using namespace sf;

class Component;

class TransformComponent : public Component {
private:
	const string m_Type = "transform";
	Vector2f m_Location;
	float m_Height;
	float m_Width;
	float m_Facing = 180;

public:
	TransformComponent(
		float width, float height, Vector2f location);

	Vector2f& getLocation();

	Vector2f getSize();

	/****************************************************
	*****************************************************
	From Component interface
	*****************************************************
	*****************************************************/

	string getType()
	{
		return m_Type;
	}

	string getSpecificType()
	{
		// Only one type of Transform so just return m_Type
		return m_Type;
	}

	void disableComponent() {}

	void enableComponent() {}

	bool enabled()
	{
		return false;
	}

	void start(GameObjectSharer* gos, GameObject* self) {}

};