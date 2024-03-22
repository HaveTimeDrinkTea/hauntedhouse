#include "Room.h"
#include <iostream>
#include "CommonDefinitions.h"

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

int Room::getNumItems()
{
	return (int)_items.size();
}

void Room::displayRooms()
{
	for (int i = 0; i < 4; i++)
	{
		if (_linkedRooms[i] != nullptr)
		{
			cout << "[" << i+1 << "]" << " Move " << DirectionNames[i] << " - " << _linkedRooms[i]->getName() << "`\n";
		}
	}
}

void Room::setItem(Item* i)
{
	_items.push_back(i);
}

void Room::removeItem(Item* i)
{
	_items.erase( remove(_items.begin(), _items.end(), i), _items.end() );
}

Item* Room::getItem(int idx)
{
	return _items[idx];
}

void Room::displayItems()
{
	for (int i = 0; i < _items.size(); i++)
	{
		//cout << "[" << i + 1 << "]" << " " << _items[i]->getName() << " - " << _items[i]->getPosDesc() << "`\n";
		cout << "[" << i + 1 << "]" << " " << _items[i]->getDisplayString() << "`\n";
	}
}