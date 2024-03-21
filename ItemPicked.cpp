#include "ItemPicked.h"
#include "ActionPick.h"
#include "ActionDrop.h"

ItemPicked::ItemPicked(string name, string desc, string dp) : Item(name, desc, dp)
{
	setAction(new ActionPick());
}

void ItemPicked::picked()
{
	removeActions();

	setAction(new ActionDrop());

	setState(Picked);
}


void ItemPicked::dropped()
{
	removeActions();
	setAction(new ActionPick());

	setState(Dropped);
}
