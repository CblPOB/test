#pragma once
#include <vector>
#include "Item.h"

using namespace std;

class Room
{
	Room *top;
	Room *bottom;
	Room *right;
	Room *left;
	vector<Item*> items;
	pair<int, int> position;
	bool isDark;

public:
	Room();
	~Room();

	void setTop(Room*);
	void setBottom(Room*);
	void setRight(Room*);
	void setLeft(Room*);
	void addItem(Item*);
	void removeItem(Item*);
	Room *getTop();
	Room *getBottom();
	Room *getRight();
	Room *getLeft();
	vector<Item*> getItems();
	void setPosition(pair<int, int>);
	pair<int, int> getPosition();
	bool isRoomDark();
	Item *getItem(string);
};

