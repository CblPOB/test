#include "View.h"



View::View()
{
}


View::~View()
{
}

void View::showInitMessage()
{
	cout << START_MESSAGE;
}

void View::showWrongMapArgumentsMessage()
{
	cout << WRONG_MAP_ARGS_MSG;
}

void View::showRoomMessage(pair<int, int> location, int doorsNum, vector<string> directions, vector<string> itemsNames)
{
	string dirs = "",
		items = "";
	for (int i = 0; i < directions.size() - 1; i++) {
		dirs += directions[i];
		dirs += " ,";
	}
	dirs += directions[directions.size() - 1];

	
	cout << "________________________________________________________________________________\n";

	if (itemsNames.size()) {
		for (int i = 0; i < itemsNames.size() - 1; i++) {
			items += itemsNames[i];
			items += ", ";
		}
		items += itemsNames[itemsNames.size() - 1];
	}
	cout << "You are in the room [" << location.first << "," << location.second
		<< "]. There are [" << doorsNum << "] doors: ["
		<< dirs << "].";
	if (itemsNames.size()) {
		cout << " Items in the room: [" << items << "].\n";
	}
	else {
		cout << " This room is empty like your pointless life.\n";
	}
	cout << "________________________________________________________________________________\n" << YOU;
}

void View::showWrongCommandMessage()
{
	cout << WRONG_COMMAND_MSG << YOU;
}

void View::showWrongDirectionMessage()
{
	cout << WRONG_DIRECTION_MSG << YOU;
}

void View::showFailedGetMessage()
{
	cout << FAILED_GET_MSG << YOU;
}

void View::showFailedOpenMessageKey()
{
	cout << FAILED_OPEN_MSG_KEY;
}

void View::showFailedOpenMessageChest()
{
	cout << FAILED_OPEN_MSG_CHEST << YOU;
}

void View::showSuccessfulGetMessage(string itemName)
{
	cout << SUCCESSFUL_GET_MSG << itemName << "]." << YOU;
}

void View::showSuccessfulOpenMessage()
{
	cout << SUCCESSFUL_OPEN_MSG;
}

void View::showHealthPointsMessage(int hp)
{
	cout << "You have " << hp << " healthpoints left.\n" << YOU;
}

void View::showDeathMessage()
{
	cout << END_MESSAGE;
}

void View::showDarkRoomMessage()
{
	cout << DARK_ROOM_MSG << YOU;
}

void View::showInventoryMessage(vector<string> items)
{
	if (items.size()) {
		for (int i = 0; i < items.size(); i++) {
			cout << items[i] << "\n";
		}
		cout << YOU;
	}
	else {
		cout << "Your inventory is empty.\n" << YOU;
	}
	
}

void View::showHelpMessage()
{
	cout << "Here is commands list:\nN :go to the north direction,\nS :go to the south direction,\nW :go to the west direction,\nE :go to the west direction,\nget [item name] :get item [item name],\ndrop [item name] :drop item [item name],\nopen [item name] :open item [item name]\nHP :show your health points,\neat :eat food,\ninventory :show inventory.\n" << YOU;
}

void View::showSuccessfulEatMessage()
{
	cout << SUCCESSFUL_EAT_MSG << 1 << " points.\n" << YOU;
}

void View::showSuccessfulDropMessage(string itemName)
{
	cout << SUCCESSFUL_DROP_MSG << itemName << "].\n" << YOU;
}

void View::showFailedEatMessage()
{
	cout << FAILED_EAT_MSG << YOU;
}

void View::showFailedDropMessage()
{
	cout << FAILED_DROP_MSG << YOU;
}

void View::showSuccessfulGetGoldMessage(long value)
{
	cout << SUCCESSFUL_GET_MSG << "gold (" << value << " coins)].\n" << YOU;
}
