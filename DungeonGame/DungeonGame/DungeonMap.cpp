#include "DungeonMap.h"



DungeonMap::DungeonMap()
{
	view.showInitMessage();
}

DungeonMap::~DungeonMap()
{
	delete this;
}

int DungeonMap::setWidthHeight(int width, int height)
{
	if (width <= 0 || height <= 0) {
		view.showWrongMapArgumentsMessage();
		return -1;
	}
	else {
		this->width = width;
		this->height = height;
		createLabyrinth();
		createRoomMessage();
		player.increaseHP(width*height*0.8);
		return 0;
	}
}

int DungeonMap::goNorth()
{
	Room *destanationRoom = getRoom(player.getPosition())->getTop();
	if (destanationRoom) {
		player.setPosition(destanationRoom->getPosition());
		if (player.reduceHP(1)) {
			view.showDeathMessage();
			return 1;
		}
		else {
			createRoomMessage();
		}
		
		return 0;
	}
	else {
		view.showWrongDirectionMessage();
		return -1;
	}

}

int DungeonMap::goSouth()
{
	Room *destanationRoom = dungeon[player.getPosition().first][player.getPosition().second].getBottom();
	if (destanationRoom) {
		player.setPosition(destanationRoom->getPosition());
		if (player.reduceHP(1)) {
			view.showDeathMessage();
			return 1;
		}
		else {			
			createRoomMessage();			
		}
		return 0;
	}
	else {
		view.showWrongDirectionMessage();
		return -1;
	}
}

int DungeonMap::goWest()
{
	Room *destanationRoom = dungeon[player.getPosition().first][player.getPosition().second].getLeft();
	if (destanationRoom) {
		player.setPosition(destanationRoom->getPosition());
		if (player.reduceHP(1)) {
			view.showDeathMessage();
			return 1;
		}
		else {
			createRoomMessage();
		}
		return 0;
	}
	else {
		view.showWrongDirectionMessage();
		return -1;
	}
}

int DungeonMap::goEast()
{
	Room *destanationRoom = dungeon[player.getPosition().first][player.getPosition().second].getRight();
	if (destanationRoom) {
		player.setPosition(destanationRoom->getPosition());
		if (player.reduceHP(1)) {
			view.showDeathMessage();
			return 1;
		}
		else {
			createRoomMessage();
		}
		
		return 0;
	}
	else {
		view.showWrongDirectionMessage();
		return -1;
	}
}

int DungeonMap::getItem(string itemName)
{
	Room *room = getRoom(player.getPosition());
	vector<Item*> items = room->getItems();
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == itemName && items[i]->isItemDraggable()) {
			if (items[i]->getName() == "gold") {
				Gold *roomGold = (Gold*)items[i];

				if (Gold *playerGold = (Gold*)player.getItem("gold")) {	
					playerGold->addCoins(roomGold->getCoins());
				}
				else {
					player.addItem(items[i]);
				}
				view.showSuccessfulGetGoldMessage(roomGold->getCoins());
				
			}
			else {
				player.addItem(items[i]);
				view.showSuccessfulGetMessage(items[i]->getName());
			}
			room->removeItem(items[i]);
			return 0;
		}
	}
	view.showFailedGetMessage();
	return -1;
}

int DungeonMap::openChest()
{
	Room *room = getRoom(player.getPosition());
	vector<Item*> items = room->getItems();

	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "chest") {
			if (player.isHaveKey()) {
				view.showSuccessfulOpenMessage();
				return 0;
			}
			else {
				view.showFailedOpenMessageKey();
				return -1;
			}
		}
	}

	view.showFailedOpenMessageChest();
	return -2;
}

void DungeonMap::showHP()
{
	view.showHealthPointsMessage(player.getHP());
}

void DungeonMap::eat()
{
	Room *room = getRoom(player.getPosition());
	vector<Item*> items = room->getItems();
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == "food") {
			player.increaseHP(1);
			room->removeItem(items[i]);
			view.showSuccessfulEatMessage();
			return;
		}
	}
	view.showFailedEatMessage();
}

void DungeonMap::drop(string itemName)
{
	Room *room = getRoom(player.getPosition());
	vector<Item*> items = player.getInventory();
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getName() == itemName) {
			room->addItem(items[i]);
			player.removeItem(items[i]);
			view.showSuccessfulDropMessage(itemName);
			return;
		}
	}

	view.showFailedDropMessage();
}

void DungeonMap::showInventory()
{
	vector<string> itemsNames;

	for (int i = 0; i < player.getInventory().size(); i++) {
		if (player.getInventory()[i]->getName() == "gold") {
			Gold *gold = (Gold*)player.getInventory()[i];
			itemsNames.insert(itemsNames.end(), (string) "gold (" + to_string(gold->getCoins()) + ")");
		}
		else {
			itemsNames.insert(itemsNames.end(), player.getInventory()[i]->getName());
		}
	}
	view.showInventoryMessage(itemsNames);

}

void DungeonMap::createLabyrinth()
{
	vector<vector<Room>> dngn(width, vector<Room>(height));
	dungeon = dngn;
	vector<int> set(width);
	vector<int> *freeNums = new vector<int>(width);
	vector<int> setsSizes;
	int numOfSets;
	for (int i = 0; i < width; i++)
	{
		set[i] = i;
		(*freeNums)[i] = i;
		dungeon[i][0].setTop(NULL);
		dungeon[i][height - 1].setBottom(NULL);
	}

	for (int j = 0; j < height - 1; j++)
	{
		dungeon[0][j].setLeft(NULL);
		dungeon[width - 1][j].setRight(NULL);

		srand(time(NULL)); // track that

		for (int i = 0; i < width - 1; i++)
		{

			// creating vertical bounds

			if (set[i] == set[i + 1] || rand() % 2 == 1)
			{
				dungeon[i][j].setRight(NULL);
				dungeon[i + 1][j].setLeft(NULL);
			}
			else
			{
				dungeon[i][j].setRight(&dungeon[i + 1][j]);
				dungeon[i + 1][j].setLeft(&dungeon[i][j]);
				set[i + 1] = set[i];
			}
		}

		// creating horizontal bounds
		numOfSets = calculateNumOfSets(set);
		setsSizes = calculateSetsSizes(set, numOfSets);
		vector<int> oneElementWithoutBotBoundPerSet(numOfSets);
		int setsIterator = 0;
		int setsElemsIterator = 0;

		for (int i = 0; i < numOfSets; i++)
		{
			oneElementWithoutBotBoundPerSet[i] = rand() % setsSizes[i];
		}

		for (int i = 0; i < width; i++, setsElemsIterator++)
		{
			if (setsSizes[setsIterator] == setsElemsIterator)
			{
				setsIterator++;
				setsElemsIterator = 0;
			}
			if (rand() % 2 && oneElementWithoutBotBoundPerSet[setsIterator] != setsElemsIterator)
			{
				dungeon[i][j].setBottom(NULL);
				dungeon[i][j + 1].setTop(NULL);
				set[i] = -1;
			}
			else
			{
				dungeon[i][j].setBottom(&dungeon[i][j + 1]);
				dungeon[i][j + 1].setTop(&dungeon[i][j]);
			}
		}

		// preparation for next step


		for (int i = 0; i < width; i++)
		{
			if (set[i] == -1)
			{
				continue;
			}
			for (int j = 0; j < freeNums->size(); j++)
			{
				if ((*freeNums)[j] == set[i])
				{
					freeNums->erase(freeNums->begin() + j);
					break;
				}
			}
		}

for (int i = 0; i < width; i++)
{
	if (set[i] == -1)
	{
		set[i] = (*freeNums)[0];
		freeNums->erase(freeNums->begin());
	}
}

free(freeNums);
freeNums = new vector<int>(width);
for (int i = 0; i < width; i++)
(*freeNums)[i] = i;
	}

	for (int i = 0; i < width - 1; i++)
	{
		// creating vertical bounds (for the last row)

		if (set[i] == set[i + 1] || rand() % 2 == 1)
		{
			dungeon[i][height - 1].setRight(NULL);
			dungeon[i + 1][height - 1].setLeft(NULL);
		}
		else
		{
			dungeon[i][height - 1].setRight(&dungeon[i + 1][height - 1]);
			dungeon[i + 1][height - 1].setLeft(&dungeon[i][height - 1]);
			set[i + 1] = set[i];
		}
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			pair<int, int> position(i, j);
			dungeon[i][j].setPosition(position);
		}
	}

	setItemsInRooms();
}

void DungeonMap::createRoomMessage()
{
	Room *room = getRoom(player.getPosition());

	if (room->isRoomDark() && player.getItem("torchlight") == nullptr
		&& room->getItem("torchlight") == nullptr) {
		view.showDarkRoomMessage();
	}
	else {

		vector<string> directions;
		vector<string> itemsNames;


		if (room->getTop())
			directions.insert(directions.end(), "N");
		if (room->getBottom())
			directions.insert(directions.end(), "S");
		if (room->getLeft())
			directions.insert(directions.end(), "W");
		if (room->getRight())
			directions.insert(directions.end(), "E");

		for (int i = 0; i < room->getItems().size(); i++) {
			itemsNames.insert(itemsNames.end(), room->getItems()[i]->getName());
		}

		view.showRoomMessage(player.getPosition(), directions.size(), directions, itemsNames);
	}
}

Room * DungeonMap::getRoom(pair<int, int> coordinates)
{
	return &dungeon[coordinates.first][coordinates.second];
}

void DungeonMap::setItemsInRooms()
{
	ItemFactory factory;
	factory.add<Key>("key");
	factory.add<Chest>("chest");
	factory.add<Food>("food");
	factory.add<Gold>("gold");
	factory.add<Torchlight>("torchlight");

	vector<pair<int, int>> uniqueCoordinates(3, pair<int, int>(0, 0));

	for (int i = 0; i < 3; i++)
	{
		uniqueCoordinates[i].first = rand() % width;
		uniqueCoordinates[i].second = rand() % height;
	}

	getRoom(uniqueCoordinates[0])->addItem(factory.create("key"));
	getRoom(uniqueCoordinates[1])->addItem(factory.create("chest"));
	player.setPosition(uniqueCoordinates[2]);
	Item *randomItem;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			randomItem = getRandomItem(&factory);
			if (randomItem != nullptr) {
				dungeon[i][j].addItem(randomItem);
			}
		}
	}
}

Item * DungeonMap::getRandomItem(ItemFactory *factory)
{
	int randomItem = rand() % 4;
	switch (randomItem)
	{
	case 0:
		return nullptr;
		break;
	case 1:
		return factory->create("food");
		break;
	case 2:
		return factory->create("gold");
		break;
	case 3:
		return factory->create("torchlight");
	}
}

vector<int> DungeonMap::calculateSetsSizes(vector<int> set, int numOfSets)
{
	vector<int> setsSizes(numOfSets, 1);
	int setNum = 0;
	
	for (int i = 0; i < width - 1; i++)
	{
		
		if (set[i] != set[i + 1])
		{
			setNum++;
		}
		else {
			setsSizes[setNum]++;
		}
	}

	return setsSizes;
}

int DungeonMap::calculateNumOfSets(vector<int> set)
{
	int counter = 1;
	for (int i = 0; i < width - 1; i++)
	{
		if (set[i] != set[i + 1])
		{
			counter++;
		}
	}
	return counter;
}