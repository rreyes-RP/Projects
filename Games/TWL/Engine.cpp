/*
 * Created by Rorie Reyes on 10/24/22.
 */

#include "Engine.h"

/*
 * Engine class
 */
Engine::Engine() {
    /*
     * Get the screen resolution and create an SFML Window and View
     */
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y), "Thomas Was Late",
                    Style::Default);
    m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

    // Initialize the split screen
    m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

    m_RightView.setViewport(FloatRect(0.5f,0.001f,0.499f,0.998f));

    m_BGLeftView.setViewport(FloatRect(0.001f,0.001f,0.498f,0.998f));

    m_BGRightView.setViewport(FloatRect(0.5f,0.001f,0.498f,0.998f));

    /*
     * Can this graphics card use shaders
     */
    if (!sf::Shader::isAvailable()) {
        m_Window.close();
    }

    else {
        m_RippleShader.loadFromFile("shaders/vertShader.vert","shaders/rippleShader.frag");
    }

    m_BackgroundTexture = TextureHolder::GetTexture("graphics/sky_background.png");

    m_BackgroundSprite.setTexture(m_BackgroundTexture); // Associate the sprite with the texture

    m_TextureTiles = TextureHolder::GetTexture("graphics/new_tiles_sheet.png"); // Load the texture for the background

    m_PS.init(1000); // Initialize the particle system

}

/*
 * run class
 */
void Engine::run() {
    Clock clock; // Timing

    while (m_Window.isOpen()) {
        Time dt = clock.restart();

        m_GameTimeTotal += dt; // Update the total game time

        float dtAsSeconds = dt.asSeconds(); // Make a decimal fraction from the delta time

        input(); // Call each part of the game loop in turn

        update(dtAsSeconds);
        draw();
    }

}


