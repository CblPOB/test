#pragma once
#include "Item.h"
class Torchlight :
	public Item
{
public:
	Torchlight();
	~Torchlight();
	string getName();
	bool isItemDraggable();
};

