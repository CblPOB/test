#pragma once
#include "ItemCreator.h"
#include "Key.h"
#include "Chest.h"
#include "Food.h"
#include "Gold.h"
#include "Torchlight.h"
#include <map>

class ItemFactory
{
protected:
	typedef std::map<std::string, AbstractItemCreator*> FactoryMap;
	FactoryMap factory;
public:
	ItemFactory();
	~ItemFactory();

	template <class C>
	void add(const string& id)
	{
		factory[id] = new ItemCreator<C>();
	}

	Item *create(const string&);
};

