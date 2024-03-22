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
	virtual ~Item() {}

	void setPosDesc(string s);
	string getPosDesc();

	void setAction(Action* a);
	Action* getAction(int idx);
	void displayActions();
	int getNumActions();
	string getDisplayString();

	void setHoldingItem(Item* it);
	Item* getHoldingItem(int idx);
	int getNumHoldingItems();
	void removeHoldingItem(Item* it);
	void displayHoldingItems();

	void setParent(Item* p);
	Item* getParent();

	void setState(ItemState s);
	ItemState getState();

	virtual void picked();
	virtual void stored();
	virtual void wore();
	virtual void lighted();
	virtual void hanged();
	virtual void dropped();

protected:
	void removeActions();
	string _posDesc;
	vector<Action*> _actions = {};
	ItemState _state;
	vector<Item*> _holding = {};
	Item* _parent;
};

#endif