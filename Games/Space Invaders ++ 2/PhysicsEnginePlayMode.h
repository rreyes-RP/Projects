#pragma once
#include "GameObjectSharer.h"
#include "PlayerUpdateComponent.h"

class PhysicsEnginePlayMode {

public:
    void initilize(GameObjectSharer& gos);
    void detectCollisions( vector<GameObject>& objects, const vector<int>& bulletPositions);

private:
	shared_ptr<PlayerUpdateComponent> m_PUC;

	GameObject* m_Player;
	bool m_InvaderHitWallThisFrame = false;
	bool m_InvaderHitWallPreviousFrame = false;
	bool m_NeedToDropDownAndReverse = false;
	bool m_CompletedDropDownAndReverse = false;
    bool m_UfoHitWallThisFrame = false;
    bool m_UfoHitWallPreviousFrame = false;


	void detectInvaderCollisions(vector<GameObject>& objects, const vector<int>& bulletPositions);

    void detectUfoCollisions(vector<GameObject>& objects, const vector<int>& bulletPositions);

	void detectPlayerCollisionsAndInvaderDirection(vector<GameObject>& objects, const vector<int>& bulletPositions);

	void handleInvaderDirection();

    void handleUfoDirection();

};

