#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include "MainObject.h"
#include "CommonDefinitions.h"


class Action;

class Item : public MainObject
{
public:
	Item(const string name, const string desc, const string posDesc);

	void setPosDesc(string s);
	string getPosDesc();

	void setAction(Action* a);
	void displayActions();
	int getNumActions();
	string getDisplayString();

	void setHoldingItem(Item* it);
	Item* getHoldingItem(int idx);
	int getNumHoldingItems();
	void removeHoldingItem(Item* it);

	void setParent(Item* p);
	Item* getParent();

	void setState(ItemState s);
	ItemState getState();

protected:
	void removeActions();
	string _posDesc;
	vector<Action*> _actions = {};
	ItemState _state;
	vector<Item*> _holding = {};
	Item* _parent;
};

#endif