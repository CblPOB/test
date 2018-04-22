#include "Player.h"



Player::Player()
{
	healthPoints = 0;
}


Player::~Player()
{
}

void Player::addItem(Item *itemName)
{
	inventory.insert(inventory.end(), itemName);
}

int Player::removeItem(Item* item)
{
	for (int i = 0; i < inventory.size(); i++){
		if (item == inventory[i]) {
			inventory.erase(inventory.begin() + i);
			return 0;
		}
	}
	return 1;
}

int Player::reduceHP(int value)
{
	healthPoints -= value;
	if (healthPoints > 0)
		return 0;
	else 
		return 1;
}

void Player::increaseHP(int value)
{
	healthPoints += value;
}

void Player::setPosition(pair<int, int> position)
{
	this->position = position;
}

pair<int, int> Player::getPosition()
{
	return this->position;
}

bool Player::isHaveKey()
{
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getName() == "key") {
			return true;
		}
	}
	return false;
}

int Player::getHP()
{
	return healthPoints;
}

vector<Item*> Player::getInventory()
{
	return inventory;
}

Item * Player::getItem(string itemName)
{
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getName() == itemName) {
			return inventory[i];
		}
	}
	return nullptr;
}
