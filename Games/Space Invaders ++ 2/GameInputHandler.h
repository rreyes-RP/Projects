#pragma once
#include "InputHandler.h"
#include "PlayerUpdateComponent.h"
#include "TransformComponent.h"

class GameScreen;

class GameInputHandler : public InputHandler {
public:

	void initialize();
	void handleGamepad() override;
	void handleKeyPressed(Event& event, RenderWindow& window) override;

	void handleKeyReleased(Event& event, RenderWindow& window) override;

private:
    shared_ptr<PlayerUpdateComponent> m_PUC;
    shared_ptr<TransformComponent> m_PTC;

    bool mBButtonPressed = false;
};
