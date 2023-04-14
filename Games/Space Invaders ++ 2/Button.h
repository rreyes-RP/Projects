#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Button {
public:
	string m_Text;
	FloatRect m_Collider;

	Button(Vector2f position, float width, float height, int red, int green, int blue, string text);

	void draw(RenderWindow& window);

private:
    RectangleShape m_Button;
    Text m_ButtonText;
    Font m_Font;
};