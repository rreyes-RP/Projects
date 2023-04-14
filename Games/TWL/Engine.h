/*
 * Created by Rorie Reyes on 10/23/22.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"

using namespace sf;

class Engine {
public:
    Engine();

    void run(); // Run will call all the private functions
private:
    TextureHolder th;

    ParticleSystem m_PS; // create particle system

    Thomas m_Thomas;
    Bob m_Bob;

    LevelManager m_LM; // Manage all levels

    SoundManager m_SM; // Create SoundManager

    /*
     * The HUD
     */
    Hud m_Hud;
    int m_FramesSinceLastHUDUpdate = 0;
    int m_TargetFramesPerHUDUpdate = 500;

    const int TILE_SIZE = 50;
    const int VERTS_IN_QUAD = 4;

    const int GRAVITY = 300; // The force pushing the characters down

    RenderWindow m_Window;

    /*
     * Main Views
     */
    View m_MainView;
    View m_LeftView;
    View m_RightView;

    /*
     * Tree views for the background
     */
    View m_BGMainView;
    View m_BGLeftView;
    View m_BGRightView;

    View m_HudView;

    Sprite m_BackgroundSprite; // Sprite background
    Texture m_BackgroundTexture; // Texture background

    Shader m_RippleShader; // Declare a shader for the background

    bool m_Playing = false; // Game playing

    bool m_Character1 = true; // Character 1 or 2 focus

    bool m_SplitScreen = false; // Start in fullscreen

    float m_TimeRemaining = 10; // Time left in the current level (seconds)
    Time m_GameTimeTotal;

    bool m_NewLevelRequired = true; // New/first level

    VertexArray m_VALevel; // Vertex array for the level tiles

    int** m_ArrayLevel = NULL; // 2D array with the map for the level

    Texture m_TextureTiles; // Texture for level tiles

    /*
     * Private functions for internal use only
     */
    void input();
    void update(float dsAsSeconds);
    void draw();

    void loadLevel(); // Load a new level

    bool detectCollisions (PlayableCharacter& character);

    void populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel); // Make a vector of the best places to emit sounds from

    vector<Vector2f> m_FireEmitters; // Vector of Vectorf for the fire emitter locations

};
