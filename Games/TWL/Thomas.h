//
// Created by Rorie Reyes on 10/27/22.
//

#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter {
public:
    Thomas();

    bool virtual handleInput();

};
