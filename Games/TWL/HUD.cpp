//
// Created by Rorie Reyes on 11/6/22.
//

#include "HUD.h"

Hud::Hud() {
    Vector2u resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Font.loadFromFile("fonts/Roboto-Light.ttf"); // Load Font

    /*
     * When paused
     */
    m_StartText.setFont(m_Font);
    m_StartText.setCharacterSize(100);
    m_StartText.setFillColor(Color::White);
    m_StartText.setString("Press Enter when ready!");

    FloatRect textRect = m_StartText.getLocalBounds(); // Position text

    m_StartText.setOrigin(textRect.left + textRect.width / 2.0f,
                          textRect.top + textRect.height / 2.0f);

    m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

    /*
     * Time
     */
    m_TimeText.setFont(m_Font);
    m_TimeText.setCharacterSize(75);
    m_TimeText.setFillColor(Color::White);
    m_TimeText.setPosition(25, 0);
    m_LevelText.setString("1");
}

Text Hud::getMessage() {
    return m_StartText;
}

Text Hud::getLevel() {
    return m_LevelText;
}

Text Hud::getTime() {
    return m_TimeText;
}

void Hud::setLevel(String text) {
    m_LevelText.setString(text);
}

void Hud::setTime(String text) {
    m_TimeText.setString(text);
}