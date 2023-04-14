#include <sstream>
#include "InputHandler.h"

using namespace sf;
using namespace std;

void InputHandler::initialiseInputHandler(ScreenManagerRemoteControl* sw,vector<shared_ptr<Button>> buttons,
                                          View* pointerToUIView, Screen* parentScreen) {
	m_ScreenManagerRemoteControl = sw;
	m_Buttons = buttons;
	m_PointerToUIPanelView = pointerToUIView;
	m_ParentScreen = parentScreen;
}

void InputHandler::handleInput(RenderWindow& window, Event& event) {
	/*
	 * Handle any key presses
	 */
	if (event.type == Event::KeyPressed) {
		handleKeyPressed(event, window);
	}

	if (event.type == Event::KeyReleased) {
		handleKeyReleased(event, window);
	}

    if(event.key.code == Keyboard::P) {
        std::cerr << "play in select mode\n";
        string playText = "Play";
        handleLeftClick(playText, window);
    }

    else if(event.key.code == Keyboard::Q) {
        std::cerr << "quit in select mode\n";
        string quitText = "Quit";
        handleLeftClick(quitText, window);
    }

    else if(event.key.code == Keyboard::H) {
        std::cerr << "home in select mode\n";
        string homeText = "Home";
        handleLeftClick(homeText, window);
    }

	handleGamepad();
}

void InputHandler::handleGamepad() {
    // Do nothing unless handled by a derived class
}

void InputHandler::handleKeyPressed(Event& event, RenderWindow& window){
    // Do nothing unless handled by a derived class
}

void InputHandler::handleKeyReleased(Event& event, RenderWindow& window) {
    // Do nothing unless handled by a derived class
}

void InputHandler::handleLeftClick(string& buttonInteractedWith, RenderWindow& window) {
    // Do nothing unless handled by a derived class
}

View* InputHandler::getPointerToUIView() {
	return m_PointerToUIPanelView;
}

ScreenManagerRemoteControl* InputHandler::getPointerToScreenManagerRemoteControl() {
	return m_ScreenManagerRemoteControl;
}

Screen* InputHandler::getmParentScreen() {
	return m_ParentScreen;
}