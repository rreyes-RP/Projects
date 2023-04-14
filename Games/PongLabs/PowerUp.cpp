//
// Created by Rorie Reyes on 11/3/22.
//

#include "PowerUp.h"

PowerUp::PowerUp(int type) {
    m_Type = type;

    if (m_Type == 1){
        m_Value = SPEED_EXTRA_VALUE;
    }

    m_SecondsToLive = START_SECONDS_TO_LIVE;
    m_SecondsToWait = START_WAIT_TIME;
}

void PowerUp::upgrade() {
    if (m_Type == 1) {
        m_Value += (SPEED_EXTRA_VALUE * 0.5);
    }

    m_SecondsToLive += (START_SECONDS_TO_LIVE / 10);
    m_SecondsToWait += (START_WAIT_TIME / 10);
}