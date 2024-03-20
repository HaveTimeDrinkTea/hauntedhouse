#pragma once

#include "MainObject.h"

using namespace std;

class Room : public MainObject
{
public:
	Room(const string name, const string desc);

    Room* getLinkedRoom(int index);
    void setLinkedRoom(int index, Room* r);

    Room* getSmallPassage(int index);
    void setSmallPassage(int index, Room* r);

    void Displayrooms();

    //TO DO: add set and get functions for items and add code to cpp file

private:
    Room* _linkedRooms[4];
    Room* _smallPassage[4];

    string _directionNames[4] = { "North", "West", "South", "East" };

    //TO DO: add a container for the room items
    // vector<Items> _roomItems;
};

