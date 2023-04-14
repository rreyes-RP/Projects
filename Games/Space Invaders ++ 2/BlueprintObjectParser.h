#pragma once
#include "GameObjectBlueprint.h"
#include <string>

using namespace std;

class BlueprintObjectParser {
public:
	void parseNextObjectForBlueprint(
		ifstream& reader, GameObjectBlueprint& bp);

private:
    string extractStringBetweenTags(
            string stringToSearch, string startTag, string endTag);
};