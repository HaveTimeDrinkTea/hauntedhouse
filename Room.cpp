#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(const string name, const string desc) : MainObject(name,desc)
{
	for (int i = 0; i < 4; i++)
	{
		_linkedRooms[i] = nullptr;
		_smallPassage[i] = nullptr;
	}
}

void Room::setLinkedRoom(int idx, Room* r)
{
	_linkedRooms[idx] = r;
}

Room* Room::getLinkedRoom(int idx)
{
	return _linkedRooms[idx];
}

void Room::setSmallPassage(int idx, Room* r)
{
	_smallPassage[idx] = r;
}

Room* Room::getSmallPassage(int idx)
{
	return _smallPassage[idx];
}

void Room::Displayrooms()
{
	for (int i = 0; i < 4; i++)
	{
		if (_linkedRooms[i] != nullptr)
		{
			cout << "[" << i+1 << "]" << " Move " << _directionNames[i] << " - " << _linkedRooms[i]->getName() << "`\n";
		}
	}
}