#pragma once
#include "ItemPicked.h"
class ItemPickedWore : public ItemPicked
{
public:
	ItemPickedWore(string name, string desc, string dp);

	void picked();
	void wore();
	void hang();
};

