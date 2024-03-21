#include "ItemPickedStored.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ActionDrop.h"

ItemPickedStored::ItemPickedStored(string name, string desc, string dp) : ItemPicked(name, desc, dp)
{
	setAction(new ActionStore());
}

void ItemPickedStored::picked()
{
	ItemPicked::picked();

	setAction(new ActionStore());
}

void ItemPickedStored::stored()
{
	removeActions();
	setAction(new ActionPick());
	setAction(new ActionDrop());

	setState(Stored);
}

