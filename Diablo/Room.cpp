#include <iostream>
#include "Main.h"
#include <vector>
#include "Room.h"
#include "Door.h"

Room Room::allRooms[5];

Room::Room()
{
	
}

void Room::EnterRoom()
{
	system("cls");
	Diablo();
	for (int i = 0;i < RandomizeInt(1, 3);i++)
	{
		Door door(allRooms[RandomizeInt(0,4)]);
		doors.push_back(door);
	}

	std::cout << "You have entered the first room!";
	EnterToContinue();
}