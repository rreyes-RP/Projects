//
// Created by Rorie Reyes on 10/30/22.
//

#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter {
public:
    Bob();

    bool virtual handleInput(); // Overridden input handler for Bob
};
