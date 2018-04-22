#include "Controller.h"



Controller::Controller()
{
}


Controller::~Controller()
{
}

void Controller::handleInput()
{
	
}

void Controller::startGame()
{
	int width, height;
	string command;
	string operand;
	char c = NULL;
	bool endOfGame = false;
	std::map<commands, string> commandsMap;

	commandsMap[N] = "N";
	commandsMap[W] = "W";
	commandsMap[S] = "S";
	commandsMap[E] = "E";
	commandsMap[Get] = "get";
	commandsMap[Drop] = "drop";
	commandsMap[Open] = "open";
	commandsMap[HP] = "HP";
	commandsMap[Eat] = "eat";
	commandsMap[Inventory] = "inventory";
	commandsMap[Help] = "help";
	

	cin >> width >> height;
	while (map.setWidthHeight(width, height)) {	
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
		}
		cin >> width >> height;
		
	}
	
	cin.ignore();
	int commandNum = -1;

	

	while (true) {

		std::getline(cin, command);
		if (command.find(' ')) {
			operand = command.substr(command.find(' ') + 1, command.length());
			command = command.substr(0, command.find(' '));
		}

		for (int i = 0; i < commandsMap.size(); i++) {
			if (commandsMap[(commands)i] == command) {
				commandNum = i;
				break;
			}
		}
		
		switch (commandNum) {
		
		case N:
			if (map.goNorth() == 1) {
				endOfGame = true;
			}
			break;

		case S:
			if (map.goSouth() == 1) {
				endOfGame = true;
			}
			break;

		case W:
			if (map.goWest() == 1) {
				endOfGame = true;
			}
			break;

		case E:
			if (map.goEast() == 1) {
				endOfGame = true;
			}
			break;

		case Get:
			map.getItem(operand);
			break;

		case Drop:
			map.drop(operand);
			break;

		case Open:
			if (!map.openChest()) {
				endOfGame = true;
			}
			break;

		case HP:
			map.showHP();
			break;

		case Eat:
			map.eat();
			break;

		case Inventory:
			map.showInventory();
			break;

		case Help:
			View::showHelpMessage();
			break;

		default:
			View::showWrongCommandMessage();
			break;
		}

		if (endOfGame) {
			getchar();
			break;
		}
		cin.clear();
		commandNum = -1;
	}

}

