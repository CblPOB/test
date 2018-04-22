#pragma once
#include "Item.h"


class AbstractItemCreator
{
public:
	AbstractItemCreator();
	virtual ~AbstractItemCreator();
	virtual Item *create() { return nullptr; };
};

