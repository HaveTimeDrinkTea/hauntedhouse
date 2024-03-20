#include "GameState.h"

GameState::GameState()
{

}

void GameState::setCurrentRoom(Room* r)
{
	_currentRoom = r;
}

Room* GameState::getCurrentRoom()
{
	return _currentRoom;
}
