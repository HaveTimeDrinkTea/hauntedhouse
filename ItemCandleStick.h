#pragma once
#include "ItemPickedStored.h"

class ItemCandleStick : public ItemPickedStored
{
public:
	ItemCandleStick(string dp);

	void lighted();
	void picked();

};

