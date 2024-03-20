#pragma once
#include <string>
#include <stdexcept>
#include <map>

using namespace std;

class Room
{
public:
	Room(const string name, const string desc);

    // getters
    string getName();
    string getDesc();
   

    // Setters, it is void bec it is merely setting the name/description
    void setName(string newName);
    void setDesc(string newDesc);

    Room* getLinkedRoom(int index);
    void setLinkedRoom(int index, Room* r);

    void Displayrooms();

private:
    string _name;
    string _desc;
    Room* _linkedRooms[4];

    string _directionNames[4] = { "North", "West", "South", "East" };
};

