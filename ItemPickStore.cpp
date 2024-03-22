#include "ItemPickStore.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ActionDrop.h"

ItemPickStore::ItemPickStore(string name, string desc, string dp) : ItemPick(name, desc, dp)
{
	setAction(new ActionStore());
}

void ItemPickStore::picked()
{
	ItemPick::picked();

	setAction(new ActionStore());
}

void ItemPickStore::stored()
{
	removeActions();
	setAction(new ActionPick());
	setAction(new ActionDrop());

	setState(Stored);
}

