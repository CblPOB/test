#include "Room.h"



Room::Room()
{
	top = NULL;
	bottom = NULL;
	right = NULL;
	left = NULL;
	if (rand() % 100 > 74) {
		isDark == true;
	}
	else {
		isDark = false;
	}
}


Room::~Room()
{
}

void Room::setTop(Room *val)
{
	top = val;
}

void Room::setBottom(Room *val)
{
	bottom = val;
}

void Room::setRight(Room *val)
{
	right = val;
}

void Room::setLeft(Room *val)
{
	left = val;
}

void Room::addItem(Item *item)
{
	items.insert(items.end(), item);
}

void Room::removeItem(Item* item)
{
	for (int i = 0; i < items.size(); i++) {
		if (items[i] == item) {
			items.erase(items.begin() + i);
			break;
		}
	}
}

Room* Room::getTop()
{
	return top;
}

Room* Room::getBottom()
{
	return bottom;
}

Room* Room::getRight()
{
	return right;
}

Room* Room::getLeft()
{
	return left;
}

vector<Item*> Room::getItems()
{
	return items;
}

void Room::setPosition(pair<int, int> position)
{
	this->position = position;
}

pair<int, int> Room::getPosition()
{
	return this->position;
}

bool Room::isRoomDark()
{
	return isDark;
}

Item * Room::getItem(string itemName)
{
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == itemName) {
			return items[i];
		}
	}
	return nullptr;
}



