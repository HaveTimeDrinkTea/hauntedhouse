#include "Layout.h"

Layout::Layout() 
{
	Room porch = Room("Porch", "Description");

	Room corr1 = Room("Corridor 1", "Description");
	corr1.linkedRooms["s"] = &porch;
	porch.linkedRooms["n"] = &corr1;

	Room dinn = Room("Dinning Room", "Description");
	dinn.linkedRooms["e"] = &corr1;
	corr1.linkedRooms["w"] = &dinn;

	Room hall = Room("Hall", "Description");
	hall.linkedRooms["s"] = &corr1;
	corr1.linkedRooms["n"] = &hall;

	Room study = Room("Study", "Description");
	study.linkedRooms["e"] = &hall;
	hall.linkedRooms["w"] = &study;

	Room corr2 = Room("Corridor 2", "Description");
	corr2.linkedRooms["s"] = &hall;

	Room draw = Room("Drawing Room", "Description");
	draw.linkedRooms["e"] = &corr2;
	corr2.linkedRooms["w"] = &draw;

	Room pantry1 = Room("Pantry 1", "Description");
	pantry1.linkedRooms["s"] = &corr2;
	corr2.linkedRooms["n"] = &pantry1;

	Room pantry2 = Room("Pantry 2", "Description");
	pantry2.linkedRooms["w"] = &corr2;
	corr2.linkedRooms["e"] = &pantry2;

	Room kitpass = Room("Kitchen Passage", "Description");
	kitpass.linkedRooms["w"] = &corr1;
	corr1.linkedRooms["e"] = &kitpass;

	Room couyar = Room("Courtyard", "Description");
	couyar.linkedRooms["s"] = &kitpass;
	kitpass.linkedRooms["n"] = &couyar;

	Room kitchen = Room("Kitchen", "Description");
	kitchen.linkedRooms["w"] = &kitpass;
	kitpass.linkedRooms["e"] = &kitchen;

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
