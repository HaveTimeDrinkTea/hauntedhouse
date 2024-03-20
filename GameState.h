#pragma once

#include "Room.h"

class GameState
{
public:
	GameState();

	void setCurrentRoom(Room* r);
	Room* getCurrentRoom();
	
private:
	Room* _currentRoom;
};

