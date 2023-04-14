//
// Created by Rorie Reyes on 10/31/22.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class LevelManager {
public:
    const int TILE_SIZE = 50;
    const int VERTS_IN_QUAD = 4;

    LevelManager();

    float getTimeLimit();

    Vector2f getStartPosition();

    int** nextLevel(VertexArray& rVaLevel);

    Vector2i getLevelSize();

    int getCurrentLevel();

private:
    Vector2i m_LevelSize;
    Vector2f m_StartPosition;
    float m_TimeModifier = 1;
    float m_BaseTimeLimit = 0;
    int m_CurrentLevel = 0;
    const int NUM_LEVELS = 8;

    SoundBuffer m_Level1StoryBuffer;
    SoundBuffer m_Level2StoryBuffer;
    SoundBuffer m_Level3StoryBuffer;
    SoundBuffer m_Level4StoryBuffer;
    SoundBuffer m_Level5StoryBuffer;
    SoundBuffer m_Level6StoryBuffer;
    SoundBuffer m_Level7StoryBuffer;
    SoundBuffer m_Level8StoryBuffer;

    Sound m_Level1StorySound;
    Sound m_Level2StorySound;
    Sound m_Level3StorySound;
    Sound m_Level4StorySound;
    Sound m_Level5StorySound;
    Sound m_Level6StorySound;
    Sound m_Level7StorySound;
    Sound m_Level8StorySound;
};
