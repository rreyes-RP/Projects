//
// Created by Rorie Reyes on 11/6/22.
//

#pragma once
#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager {
public:
    SoundManager();

    void playFire(Vector2f emitterLocation, Vector2f listenerLocation);

    void playFallInFire();
    void playFallInWater();
    void playFallOnSpikes();
    void playJump();
    void playReachGoal();

private:
    /*
     * Buffers
     */
    SoundBuffer m_FireBuffer;
    SoundBuffer m_FallInFireBuffer;
    SoundBuffer m_FallInWaterBuffer;
    SoundBuffer m_FallOnSpikesBuffer;
    SoundBuffer m_JumpBuffer;
    SoundBuffer m_ReachGoalBuffer;

    /*
     * Sounds
     */
    Sound m_Fire1Sound;
    Sound m_Fire2Sound;
    Sound m_Fire3Sound;
    Sound m_FallInFireSound;

    Sound m_FallInWaterSound;
    Sound m_FallOnSpikesSound;
    Sound m_JumpSound;
    Sound m_ReachGoalSound;

    int m_NextSound = 1; // Which sound should we use next: fire 1, 2, or 3
};
