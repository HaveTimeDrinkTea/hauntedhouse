#include "ItemPickStoreLight.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ActionDrop.h"
#include "ActionLight.h"

ItemPickStoreLight::ItemPickStoreLight(const string name, const string desc, const string dp) : ItemPickStore(name, desc, dp)
{
	//setAction(new ActionPick());
	//setAction(new ActionStore());
}


void ItemPickStoreLight::lighted()
{
	removeActions();
	setAction(new ActionDrop());

	setState(Lighted);
}

void ItemPickStoreLight::picked()
{
	ItemPickStore::picked();

	setAction(new ActionLight());

}

