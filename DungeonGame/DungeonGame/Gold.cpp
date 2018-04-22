#include "Gold.h"



Gold::Gold()
{
	coins = rand() % 500 + 1;
}


Gold::~Gold()
{	
}

string Gold::getName()
{
	return "gold";
}

bool Gold::isItemDraggable()
{
	return true;
}

long Gold::getCoins()
{
	return coins;
}

void Gold::addCoins(long value)
{
	coins += value;
}
