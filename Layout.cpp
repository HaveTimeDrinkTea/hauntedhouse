#include "Layout.h"
#include "CommonDefinitions.h"

Layout::Layout() 
{
	Room* porch = new Room("Porch", "Description");
	Room* corr1 = new Room("Corridor 1", "Description");
	Room* dinn = new Room("Dinning Room", "Description");
	Room* hall = new Room("Hall", "Description");
	Room* study = new  Room("Study", "Description");
	Room* corr2 = new Room("Corridor 2", "Description");
	Room* draw = new Room("Drawing Room", "Description");
	Room* pantry1 = new Room("Pantry 1", "Description");
	Room* pantry2 = new Room("Pantry 2", "Description");
	Room* kitpass = new Room("Kitchen Passage", "Description");
	Room* couyar = new Room("Courtyard", "Description");
	Room* kitchen = new Room("Kitchen", "Description");

	porch->setLinkedRoom(North, corr1);

	corr1->setLinkedRoom(North, hall);
	corr1->setLinkedRoom(East, kitpass);
	corr1->setLinkedRoom(South, porch);
	corr1->setLinkedRoom(West, dinn);

	dinn->setLinkedRoom(East, corr1);
	
	hall->setLinkedRoom(North, corr2);
	hall->setLinkedRoom(South, corr1);
	hall->setLinkedRoom(West, study);

	study->setLinkedRoom(East, hall);
	
	corr2->setLinkedRoom(North, pantry1);
	corr2->setLinkedRoom(East, pantry2);
	corr2->setLinkedRoom(South, hall);
	corr2->setLinkedRoom(West, draw);
	
	draw->setLinkedRoom(East, corr2);
	
	pantry1->setLinkedRoom(South, corr2);
	
	pantry2->setLinkedRoom(West, corr2);

	kitpass->setLinkedRoom(North, couyar);
	kitpass->setLinkedRoom(East, kitchen);
	kitpass->setLinkedRoom(West, corr1);

	couyar->setLinkedRoom( South, kitpass);
	
	kitchen->setLinkedRoom( West, kitpass);

	//TO DO: add items to the rooms
	//TO DO: store the references to the items

	
	_roomList.push_back(porch);
	_roomList.push_back(corr1);
	_roomList.push_back(dinn);
	_roomList.push_back(hall);
	_roomList.push_back(study);
	_roomList.push_back(corr2);
	_roomList.push_back(draw);
	_roomList.push_back(pantry1);
	_roomList.push_back(pantry2);
	_roomList.push_back(kitpass);
	_roomList.push_back(couyar);
	_roomList.push_back(kitchen);
}

Room* Layout::getFirstRoom()
{
	return _roomList[0];
}
