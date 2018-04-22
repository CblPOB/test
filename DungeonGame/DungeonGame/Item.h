#pragma once
#include<string>


using namespace std;

class Item
{
public:
	Item();
	virtual ~Item();
	virtual string getName() = 0;
	virtual bool isItemDraggable() = 0;
};

