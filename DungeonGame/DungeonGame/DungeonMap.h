#pragma once
#include "Room.h"
#include "Player.h"
#include "View.h"
#include "ItemFactory.h"
#include <ctime>

class DungeonMap
{
	vector<vector<Room>> dungeon;
	int width;
	Player player;
	View view;
	int height;
	vector<int> calculateSetsSizes(vector<int>, int);
	int calculateNumOfSets(vector<int>);
	void createLabyrinth();
	void createRoomMessage();
	Room *getRoom(pair<int, int>);
	void setItemsInRooms();
	Item *getRandomItem(ItemFactory*);

public:
	DungeonMap();
	~DungeonMap();
	int setWidthHeight(int, int);
	int goNorth();
	int goSouth();
	int goWest();
	int goEast();
	int getItem(string);
	int openChest();
	void showHP();
	void eat();
	void drop(string);
	void showInventory();
};

