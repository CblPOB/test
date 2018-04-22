#include "Chest.h"


Chest::Chest()
{
}

Chest::~Chest()
{
}

string Chest::getName()
{
	return "chest";
}

bool Chest::isItemDraggable()
{
	return false;
}
