/*
 * Created by Rorie Reyes on 10/24/22.
 */

#include "Engine.h"

void Engine::draw() {
    m_Window.clear(Color::White); // Rub out the last frame

    m_RippleShader.setUniform("uTime",m_GameTimeTotal.asSeconds());

    if (!m_SplitScreen) {
        m_Window.setView(m_BGMainView); // Switch background view
        //m_Window.draw(m_BackgroundSprite); // Draw background
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_MainView); // Switch to Main View
        m_Window.draw(m_VALevel, &m_TextureTiles); // Draw the level

        m_Window.draw(m_Thomas.getSprite()); // Draw Thomas

        m_Window.draw(m_Bob.getSprite()); // Draw Bob

        /*
         * Particle System
         */
        if (m_PS.running()) {
            m_Window.draw(m_PS);
        }
    }

    else {
        // Split-screen view is active

        // First draw Thomas' side of the screen

        m_Window.setView(m_BGLeftView); // Switch to background view
        //m_Window.draw(m_BackgroundSprite); // Draw the background
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_LeftView); // Switch to left view

        m_Window.draw(m_VALevel, &m_TextureTiles);

        m_Window.draw(m_Bob.getSprite()); // Draw Bob

        m_Window.draw(m_Thomas.getSprite()); // Draw Thomas

        /*
         * Particle System
         */
        if (m_PS.running()) {
            m_Window.draw(m_PS);
        }

        // Now draw Bob's side of the screen

        m_Window.setView(m_BGRightView); // Switch to background view
        //m_Window.draw(m_BackgroundSprite); // Draw the background
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_RightView); // Switch to right view

        m_Window.draw(m_VALevel, &m_TextureTiles);

        m_Window.draw(m_Thomas.getSprite()); // Draw Thomas

        m_Window.draw(m_Bob.getSprite()); // Draw Bob

        /*
         * Particle System
         */
        if (m_PS.running()) {
            m_Window.draw(m_PS);
        }
    }

    // Draw the HUD
    m_Window.setView(m_HudView); // Switch to HUD View
    m_Window.draw(m_Hud.getLevel());
    m_Window.draw(m_Hud.getTime());
    if (!m_Playing) {
        m_Window.draw(m_Hud.getMessage());
    }

    m_Window.display(); // Show everything
}
