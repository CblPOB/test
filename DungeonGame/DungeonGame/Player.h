#pragma once
#include <vector>
#include "Item.h"
#include <utility>

using namespace std;

class Player
{
	vector<Item*> inventory;
	int healthPoints;
	pair<int, int> position;

public:
	Player();
	~Player();
	void addItem(Item*);
	int removeItem(Item*);
	int reduceHP(int);
	void increaseHP(int);
	void setPosition(pair<int, int>);
	pair<int, int> getPosition();
	bool isHaveKey();
	int getHP();
	vector<Item*> getInventory();
	Item *getItem(string);
};

