#include "Food.h"



Food::Food()
{
}


Food::~Food()
{
}

string Food::getName()
{
	return "food";
}

bool Food::isItemDraggable()
{
	return false;
}
