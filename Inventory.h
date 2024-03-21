//
//  Inventory.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Pei WANG on 21/03/2024.
//
#pragma once

#include <iostream>
#include <vector>
#include "Inventory.h"

using namespace std;

class Inventory
{

public:
   //  constructors
   Inventory();

   //  check if inventory is full
   bool isFull();

   //  check if inventory is empty
   bool isEmpty();

   //  display inventory content
   void getInventory();

   //  Find an item in inventory and return position if available
   bool findInventory(Items *itemPtr);

   //  add item to inventory
   void addItem(Items *itemPtr);

   //  remove item from inventory
   void removeItem(Items *itemPtr);

private:
   std::vector<Items *> _container = {};

   int _capacity = 6;

   int _itemPosn = 0;
};
