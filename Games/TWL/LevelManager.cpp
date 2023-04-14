//
// Created by Rorie Reyes on 10/31/22.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>
#include "LevelManager.h"

using namespace sf;
using namespace std;

LevelManager::LevelManager() {
    m_Level1StoryBuffer.loadFromFile("sound/level1_story.wav");
    m_Level2StoryBuffer.loadFromFile("sound/level2_story.wav");
    m_Level3StoryBuffer.loadFromFile("sound/level3_story.wav");
    m_Level4StoryBuffer.loadFromFile("sound/level4_story.wav");
    m_Level5StoryBuffer.loadFromFile("sound/level5_story.wav");
    m_Level6StoryBuffer.loadFromFile("sound/level6_story.wav");
    m_Level7StoryBuffer.loadFromFile("sound/level7_story.wav");
    m_Level8StoryBuffer.loadFromFile("sound/level8_story.wav");

    m_Level1StorySound.setBuffer(m_Level1StoryBuffer);
    m_Level2StorySound.setBuffer(m_Level2StoryBuffer);
    m_Level3StorySound.setBuffer(m_Level3StoryBuffer);
    m_Level4StorySound.setBuffer(m_Level4StoryBuffer);
    m_Level5StorySound.setBuffer(m_Level5StoryBuffer);
    m_Level6StorySound.setBuffer(m_Level6StoryBuffer);
    m_Level7StorySound.setBuffer(m_Level7StoryBuffer);
    m_Level8StorySound.setBuffer(m_Level8StoryBuffer);
}

int** LevelManager::nextLevel(VertexArray& rVaLevel) {
    m_LevelSize.x = 0;
    m_LevelSize.y = 0;

    m_CurrentLevel++; // Next level

    if (m_CurrentLevel > NUM_LEVELS) {
        m_CurrentLevel = 1;
        m_TimeModifier -= 0.1f;
    }

    /*
     * Load the appropriate level form a text file
     */
    string levelToLoad;
    switch (m_CurrentLevel) {
        case 1:
            levelToLoad = "levels/level1.txt";
            m_StartPosition.x = 100; // 100
            m_StartPosition.y = 100; // 100
            m_BaseTimeLimit = 30.0f; // 30
            m_Level1StorySound.setRelativeToListener(true);
            m_Level1StorySound.play();
            break;

        case 2:
            levelToLoad = "levels/level2.txt";
            m_StartPosition.x = 100;
            m_StartPosition.y = 3600;
            m_BaseTimeLimit = 100.0f;
            m_Level2StorySound.setRelativeToListener(true);
            m_Level2StorySound.play();
            break;

        case 3:
            levelToLoad = "levels/level3.txt";
            m_StartPosition.x = 1250;
            m_StartPosition.y = 0;
            m_BaseTimeLimit = 30.0f;
            m_Level3StorySound.setRelativeToListener(true);
            m_Level3StorySound.play();
            break;

        case 4:
            levelToLoad = "levels/level4.txt";
            m_StartPosition.x = 50;
            m_StartPosition.y = 150;
            m_BaseTimeLimit = 100.0f;
            m_Level4StorySound.setRelativeToListener(true);
            m_Level4StorySound.play();
            break;

        case 5:
            levelToLoad = "levels/level5.txt";
            m_StartPosition.x = 100;
            m_StartPosition.y = 100;
            m_BaseTimeLimit = 100.0f;
            m_Level5StorySound.setRelativeToListener(true);
            m_Level5StorySound.play();
            break;

        case 6:
            levelToLoad = "levels/level6.txt";
            m_StartPosition.x = 1250;
            m_StartPosition.y = 0;
            m_BaseTimeLimit = 100.0f;
            m_Level6StorySound.setRelativeToListener(true);
            m_Level6StorySound.play();
            break;

        case 7:
            levelToLoad = "levels/level7.txt";
            m_StartPosition.x = 100;
            m_StartPosition.y = 3600;
            m_BaseTimeLimit = 180.0f;
            m_Level7StorySound.setRelativeToListener(true);
            m_Level7StorySound.play();
            break;

        case 8:
            levelToLoad = "levels/level8.txt";
            m_StartPosition.x = 100;
            m_StartPosition.y = 100;
            m_BaseTimeLimit = 30.0f;
            m_Level8StorySound.setRelativeToListener(true);
            m_Level8StorySound.play();
            break;

    }  // End switch

    ifstream inputFile(levelToLoad);
    string s;

    /*
     * Count the number of rows in the file
     */
    while (getline(inputFile, s)) {
        m_LevelSize.y++;
    }

    m_LevelSize.x = s.length();

    /*
     *  Go back to the start of the file
     */
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    /*
     * Prep the 2D array to hold the int values from the file
     */
    int** arrayLevel = new int* [m_LevelSize.y];
    for (int i = 0; i < m_LevelSize.y; ++i) {
        arrayLevel[i] = new int[m_LevelSize.x]; // Add new array into each array element
    }

    /*
     * Loop through the file and store all
     * the values in the 2d array
     */
    string row;
    int y = 0;
    while (inputFile >> row) {
        for (int x = 0; x < row.length(); x++) {
            const char val = row[x];
            arrayLevel[y][x] = atoi(&val);
        }

        ++y;
    }

    inputFile.close(); // Close the file

    rVaLevel.setPrimitiveType(Quads); // Type of primitive

    rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD); // Set the size of the vertex array

    int currentVertex = 0; // Start at the beginning of the vertex array

    for (int a = 0; a < m_LevelSize.x; a++) {
        for (int b = 0; b < m_LevelSize.y; b++) {
            rVaLevel[currentVertex + 0].position = Vector2f(a * TILE_SIZE, b * TILE_SIZE);

            rVaLevel[currentVertex + 1].position = Vector2f((a * TILE_SIZE) + TILE_SIZE, b * TILE_SIZE);

            rVaLevel[currentVertex + 2].position = Vector2f((a * TILE_SIZE) + TILE_SIZE, (b * TILE_SIZE) + TILE_SIZE);

            rVaLevel[currentVertex + 3].position = Vector2f((a * TILE_SIZE), (b * TILE_SIZE) + TILE_SIZE);

            /*
             * Tile from the sprite sheet
             */
            int verticalOffset = arrayLevel[b][a] * TILE_SIZE;

            rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);

            rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);

            rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);

            rVaLevel[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);

            currentVertex = currentVertex + VERTS_IN_QUAD; // Position ready for the next four vertices
        }
    }

    return arrayLevel;
} // End of nextLevel function

Vector2i LevelManager::getLevelSize() {
    return m_LevelSize;
}

int LevelManager::getCurrentLevel() {
    return m_CurrentLevel;
}

float LevelManager::getTimeLimit() {
    return m_BaseTimeLimit * m_TimeModifier;
}

Vector2f LevelManager::getStartPosition() {
    return m_StartPosition;
}

/*void LevelManager::playLevel1Story() {
    m_Level1StorySound.setRelativeToListener(true);
    m_Level1StorySound.play();
}*/
