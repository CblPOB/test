#pragma once
#include "AbstractItemCreator.h"

template <class C>
class ItemCreator :
	public AbstractItemCreator
{
public:
	virtual Item *create() { return new C(); };
};

