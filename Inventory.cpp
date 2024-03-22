//
//  Inventory.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Pei WANG on 21/03/2024.
//

#include "Inventory.h"

// Constructor
Inventory::Inventory(string n, int c, bool p)
{
    _name = n;
    _capacity = c;
    _pick = p;
}

//  check if inventory is full
bool Inventory::isFull()
{
    bool full = true;

    // check the number of elements in vector against the capacity

    if (_container.size() < _capacity)
    {
        full = false;
    }

    return full;
}

//  check if inventory is empty
bool Inventory::isEmpty()
{
    bool empty = true;
    int i = 0;

    if (_container.size() > 0)
    {
        empty = false;
    }
    return empty;
}

//  Find an item in inventory
bool Inventory::findInventory(Item* itemPtr)
{
    // checks if item is already in container
    bool hasItem = false;

    auto it = std::find(_container.begin(), _container.end(), itemPtr);

    if (it != _container.end())
    {
        _itemPosn = (int)distance(_container.begin(), it);
        return true;
    }
    else
    {
        return false;
    }
}

//  Display inventory content
void Inventory::displayInventory()
{
    cout << _name << endl << endl;
    for (int i = 0; i < _container.size(); i++)
    {
        cout << i + 1 << _container[i]->getName() << endl;
    }
}

//  add item to inventory
bool Inventory::addItem(Item* itemPtr)
{
    bool retVal = true;
    if (itemPtr == nullptr)
    {
        retVal = false;
    }
    //    check if inventory is full
    else if ((Inventory::isFull()))
    {
        if (_pick)
        {
            cout << "Can not carry more, both hands are carrying something" << endl;
        }
        else
        {
            cout << "Can not store more, the inventory is full" << endl;
        }
        retVal = false;
    }
    //    inventory not full
    else
    {
        _container.push_back(itemPtr);
    }

    return retVal;
}

Item* Inventory::getItem(int idx)
{
    return _container[idx];
}

//  remove item from inventory
void Inventory::removeItem(Item* itemPtr)
{
    // checks if item is already in container

    bool hasItem = Inventory::findInventory(itemPtr);

    // if findInventory returns true, the valueof _itemPosn will also be updated.
    if (hasItem)
    {
        auto indexToRemove = _container.erase(_container.begin() + _itemPosn);
    }
}

int Inventory::getNumItems()
{
    return (int)_container.size();
}