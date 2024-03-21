#include "ItemPickedWore.h"
#include "ActionWear.h"
#include "ActionDrop.h"
#include "ActionPick.h"

ItemPickedWore::ItemPickedWore(string name, string desc, string dp) : ItemPicked(name, desc, dp)
{

}

void ItemPickedWore::picked()
{
	ItemPicked::picked();

	setAction(new ActionWear());

	if (_parent != nullptr)
	{
		_parent->removeHoldingItem(this);
	}
}

void ItemPickedWore::wore()
{
	removeActions();

	setAction(new ActionDrop());

	_state = Wore;
}

void ItemPickedWore::hang()
{
	removeActions();

	setAction(new ActionPick());

	_state = Hanged;
}
