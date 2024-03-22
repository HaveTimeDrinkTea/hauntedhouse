#include "Item.h"
#include "Action.h"
#include <iostream>

//using namespace std;

Item::Item(const string name, const string desc, const string pd) : MainObject(name, desc)
{
	_posDesc = pd;
}

void Item::removeActions()
{
	for (Action* a : _actions)
	{
		delete a;
	}
}

string Item::getPosDesc()
{
	return _posDesc;
}
void Item::setPosDesc(string newDesc)
{
	if (newDesc.empty())
	{
		throw invalid_argument("Description must not be empty");
	}
	_posDesc = newDesc;
}

void Item::setAction(Action* a)
{
	_actions.push_back(a);
}

Action* Item::getAction(int idx)
{
	return _actions[idx];
}

int Item::getNumActions()
{
	return (int)_actions.size();
}

string Item::getDisplayString()
{
	return getName() + " - " + getPosDesc();
}

void Item::displayActions()
{
	for (int i = 0; i < _actions.size(); i++)
	{
		cout << "[" << i + 1 << "]" << " " << _actions[i]->getName() << "`\n";
	}
}

void Item::setState(ItemState s)
{
	_state = s;
}

ItemState Item::getState()
{
	return _state;
}

void Item::setHoldingItem(Item* it)
{
	_holding.push_back(it);
}

Item* Item::getHoldingItem(int idx)
{
	return _holding[idx];
}

int Item::getNumHoldingItems()
{
	return (int)_holding.size();
}

void Item::removeHoldingItem(Item* it)
{
	auto r = std::find(_holding.begin(), _holding.end(), it);

	// Check if the element was found
	if (r != _holding.end()) {
		// Erase the element from the vector
		_holding.erase(r);
	}
}

void Item::displayHoldingItems()
{
	if (_holding.size() > 0)
	{
		cout << "It has:" << endl;
	}
	for (int i = 0; i < _holding.size(); i++)
	{
		cout << "-" << _holding[i]->getName() << endl;
	}
	if (_holding.size() > 0)
	{
		cout << endl << endl;
	}
}

void Item::setParent(Item* p)
{
	_parent = p;
	p->setHoldingItem(this);
}

Item* Item::getParent()
{
	return _parent;
}

void Item::picked(){}
void Item::stored() {}
void Item::wore(){}
void Item::lighted(){}
void Item::hanged(){}
void Item::dropped(){}