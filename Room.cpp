#include "Room.h"



Room::Room(const string name, const string desc)
{
	_name = name;
	_desc = desc;
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