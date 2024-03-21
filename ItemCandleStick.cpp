#include "ItemCandleStick.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ActionDrop.h"
#include "ActionLight.h"

ItemCandleStick::ItemCandleStick(string dp) : ItemPickedStored("Candlestick", "A candlestick with candles", dp)
{
	setAction(new ActionPick());
	setAction(new ActionStore());
}


void ItemCandleStick::lighted()
{
	removeActions();
	setAction(new ActionDrop());

	setState(Lighted);
}

void ItemCandleStick::picked()
{
	ItemPickedStored::picked();

	setAction(new ActionLight());

}

