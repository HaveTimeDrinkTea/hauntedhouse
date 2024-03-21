//
//  Inventory.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Pei WANG on 21/03/2024.
//

#include "Inventory.h"

// Constructor
Inventory::Inventory() {}

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
bool Inventory::findInventory(Items *itemPtr)
{
   // checks if item is already in container
   bool hasItem = false;

   auto it = std::find(_container.begin(), _container.end(), itemPtr);

   if (it != _container.end())
   {
      _itemPosn = std::distance(_container.begin(), it);
      return true;
   }
   else
   {
      return false;
   }
}

//  Display inventory content
void Inventory::getInventory()
{
   if (Inventory::isEmpty())
   {
      std::cout << "Inventory is empty"
                << "/n";
      return;
   }
   for (int i = 0; i < _capacity; i++)
   {
      if (_container[i] != nullptr)
      {
         std::cout << "These are the items you have:\n"
                   << _container[i]->getName() << "\n";
      }
   }
}

//  add item to inventory
void Inventory::addItem(Items *itemPtr)
{
   if (itemPtr == nullptr)
   {
      return;
   }
   //    check if inventory is full
   else if ((Inventory::isFull()))
   {
      std::cout << "Container is full"
                << "\n";
   }
   //    inventory not full
   else
   {
      // checks if item is already in container

      bool hasItem = Inventory::findInventory(itemPtr);

      if (hasItem)
      {
         std::cout << "Item already in inventory. There is no need to add.";
      }
      else
      { // push back
         _container.push_back(itemPtr);
      }
   }
}

//  remove item from inventory
void Inventory::removeItem(Items *itemPtr)
{
   // checks if item is already in container

   bool hasItem = Inventory::findInventory(itemPtr);

   // if findInventory returns true, the valueof _itemPosn will also be updated.
   if (hasItem)
   {
      auto indexToRemove =
          _container.erase(_container.begin() + _itemPosn);
      std::cout << "Success! Item has been removed"
                << "\n";
   }
   else
   { // push back
      std::cout << "Sorry! No such item so nothing to remove.";
   }
}
