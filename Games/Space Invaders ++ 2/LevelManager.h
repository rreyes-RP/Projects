#pragma once
#include "GameObject.h"
#include <vector>
#include <string>
#include "GameObjectSharer.h"

using namespace std;

class LevelManager : public GameObjectSharer {
public:
	vector<GameObject>& getGameObjects();
	void loadGameObjectsForPlayMode(string screenToLoad);

	/****************************************************
	*****************************************************
	From GameObjectSharer interface
	*****************************************************
	*****************************************************/

	vector<GameObject>& getGameObjectsWithGOS() {
		return m_GameObjects;
	}

	GameObject& findFirstObjectWithTag(string tag) {
		auto it = m_GameObjects.begin();
		auto end = m_GameObjects.end();

        for (it; it != end; ++it) {

            if ((*it).getTag() == tag) {
				return (*it);
			}
		}

#ifdef debuggingErrors		
		cout <<
			"LevelManager.h findFirstGameObjectWithTag() "
			<< "- TAG NOT FOUND ERROR!"
			<< endl;
#endif	
		return m_GameObjects[0];
	}

private:
    vector<GameObject> m_GameObjects;

    const std::string WORLD_FOLDER = "world";
    const std::string SLASH = "/";

    void runStartPhase();
    void activateAllGameObjects();
};