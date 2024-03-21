#pragma once
#include "Item.h"
class ItemMove : public Item
{
public:
	ItemMove(const string name, const string desc, const string pd);

	void setDestination(Item* d);
	void displayDestinations();
	void move(int idx);

private:
	vector<Item*> _destinations = {};
	Item* _currentDest;
};

