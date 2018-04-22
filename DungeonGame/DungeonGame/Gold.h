#pragma once
#include "Item.h"
class Gold :
	public Item
{
	long coins;
public:
	Gold();
	~Gold();
	string getName();
	bool isItemDraggable();
	long getCoins();
	void addCoins(long);
};

