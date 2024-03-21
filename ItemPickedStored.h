#pragma once
#include "ItemPicked.h"

class ItemPickedStored : public ItemPicked
{
public:
	ItemPickedStored(string name, string desc, string dp);

	void picked();
	void stored();
};

