//
// Created by Rorie Reyes on 11/6/22.
//

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Hud {
public:
    Hud();
    Text getMessage();
    Text getLevel();
    Text getTime();

    void setLevel(String text);
    void setTime(String text);

private:
    Font m_Font;
    Text m_StartText;
    Text m_TimeText;
    Text m_LevelText;
};
