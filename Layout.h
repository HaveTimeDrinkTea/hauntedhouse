#pragma once

#include <vector>
#include "Room.h"

using namespace std;

class Layout
{
public:
	Layout();

private: 
	vector<Room> _roomList = {};
};

