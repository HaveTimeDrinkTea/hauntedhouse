#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(const string name, const string desc)
{
	_name = name;
	_desc = desc;

	for (int i = 0; i < 4; i++)
	{
		_linkedRooms[i] = nullptr;
	}
}

string Room::getName()
{
	return _name;
}
void Room::setName(string newName)
{
	if (newName.empty())
	{
		throw invalid_argument("Name must not be empty");
	}
	_name = newName;
}

string Room::getDesc()
{
	return _desc;
}
void Room::setDesc(string newDesc)
{
	if (newDesc.empty())
	{
		throw invalid_argument("Description must not be empty");
	}
	_desc = newDesc;
}

void Room::setLinkedRoom(int idx, Room* r)
{
	_linkedRooms[idx] = r;
}

Room* Room::getLinkedRoom(int idx)
{
	return _linkedRooms[idx];
}

void Room::Displayrooms()
{
	for (int i = 0; i < 4; i++)
	{
		if (_linkedRooms[i] != nullptr)
		{
			cout << "[" << i << "]" << " " << _directionNames[i] << " - " << _linkedRooms[i]->getName() << "`\n";
		}
	}
}