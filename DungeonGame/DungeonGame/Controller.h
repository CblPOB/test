#pragma once
#include "DungeonMap.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

enum commands { N, W, S, E, Get, Drop, Open, HP, Eat, Inventory, Help};

class Controller
{
	DungeonMap map;

public:
	Controller();
	~Controller();
	void handleInput();
	void startGame();
};

