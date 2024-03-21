#pragma once
#include "Item.h"
class ItemPicked : public Item
{
public:
	ItemPicked(string name, string desc, string dp);

	void picked();
	void dropped();

};

