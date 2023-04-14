/*
 * Created by Rorie Reyes on 9/30/22.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

using namespace sf;

int createBackground (VertexArray& rVA, IntRect arena);
Enemy* createHorde(int numNinjas, IntRect arena);
