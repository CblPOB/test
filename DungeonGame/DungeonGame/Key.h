#pragma once
#include "Item.h"
class Key :
	public Item
{
public:
	Key();
	~Key();
	string getName();
	bool isItemDraggable();
};

