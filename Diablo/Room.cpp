#include <iostream>
#include "Main.h"
#include <vector>

Room::Room()
{
	
}

void Room::EnterRoom(std::vector<Room> allRooms)
{
	for (int i = 0;i < RandomizeInt(1, 3);i++)
	{
		Door door(allRooms[RandomizeInt(0,4)]);
		doors.push_back(door);
	}
}