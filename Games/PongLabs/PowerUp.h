//
// Created by Rorie Reyes on 11/3/22.
//

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PowerUp {
public:
    PowerUp(int type);

    void upgrade();

private:
    const float SPEED_EXTRA_VALUE = 1.0f;
    const int START_WAIT_TIME = 10;
    const int START_SECONDS_TO_LIVE = 5;

    int m_Value;

    int m_Type;

    bool m_Spawned;
    float m_SecondsSinceSpawn;
    float m_SecondsSinceDeSpawn;
    float m_SecondsToLive;
    float m_SecondsToWait;
};
