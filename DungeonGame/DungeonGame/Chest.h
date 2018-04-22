#pragma once
#include "Item.h"
class Chest :
	public Item
{
public:
	Chest();
	~Chest();
	string getName();
	bool isItemDraggable();
};

