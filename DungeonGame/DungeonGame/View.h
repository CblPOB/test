#pragma once
#define START_MESSAGE "Welcome you, adventurer! Before you go in search of the Grail, please enter the dungeon rag, which you are ready to go:\n"
#define END_MESSAGE "You've died of hunger in the grim chambers of the dragon's labyrinth. Good luck next time!\n"
#define WRONG_MAP_ARGS_MSG "Sorry, can't generate dungeon with that parameters. Please, enter the correct ones:\n"
#define WRONG_COMMAND_MSG "Sorry, wrong command! Try again:\n"
#define WRONG_DIRECTION_MSG "Sorry, you can't go there!\n"
#define FAILED_GET_MSG "You can't pick up that!\n"
#define FAILED_OPEN_MSG_KEY "You don't have a key to open that chest, find the key and try again.\n"
#define FAILED_OPEN_MSG_CHEST "There is no chest in this room.\n"
#define FAILED_EAT_MSG "You can't eat that!\n"
#define FAILED_DROP_MSG "You don't have that item!\n"
#define SUCCESSFUL_GET_MSG "You picked up a ["
#define SUCCESSFUL_OPEN_MSG "Congratulations, you found what you came for!\n"
#define SUCCESSFUL_EAT_MSG "Your healthpoints increased by "
#define SUCCESSFUL_DROP_MSG "You dropped a ["
#define DARK_ROOM_MSG "\nCan't see anything in this dark place!\n"
#define YOU "\nYou: "
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

class View
{
	
public:
	View();
	~View();
	void showInitMessage();
	void showWrongMapArgumentsMessage();
	void showRoomMessage(pair<int, int>, int, vector<string>, vector<string>);
	static void showWrongCommandMessage();
	static void showHelpMessage();
	void showWrongDirectionMessage();
	void showFailedGetMessage();
	void showFailedOpenMessageKey();
	void showFailedOpenMessageChest();
	void showFailedEatMessage();
	void showFailedDropMessage();
	void showSuccessfulGetMessage(string);
	void showSuccessfulGetGoldMessage(long);
	void showSuccessfulOpenMessage();
	void showSuccessfulEatMessage();
	void showSuccessfulDropMessage(string);
	void showHealthPointsMessage(int);
	void showDeathMessage();
	void showDarkRoomMessage();
	void showInventoryMessage(vector<string>);
};

