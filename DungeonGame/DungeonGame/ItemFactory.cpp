#include "ItemFactory.h"



ItemFactory::ItemFactory()
{
}


ItemFactory::~ItemFactory()
{
}

Item * ItemFactory::create(const string &id)
{
	return factory.find(id)->second->create();
}
