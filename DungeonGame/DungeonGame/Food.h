#pragma once
#include "Item.h"
class Food :
	public Item
{
public:
	Food();
	~Food();
	string getName();
	bool isItemDraggable();
};

