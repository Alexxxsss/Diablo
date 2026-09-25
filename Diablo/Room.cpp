#include <iostream>
#include "Main.h"
#include <vector>
#include "Room.h"
#include "Door.h"
#include "Enemy.h"

Room Room::allRooms[5];

Room::Room()
{
	
}

void Room::EnterRoom(int RoomIndex)
{
	system("cls");

	int amountOfEnemies = RandomizeInt(1, 3);
	int amountOfDoores = RandomizeInt(1, 3);


	for (int i = 0;i < amountOfDoores;i++)
	{
		int roomIndex = RandomizeInt(0, 4);

		Door door(allRooms[roomIndex]);
		doors.push_back(door);
	}
	for (int i = 0;i < amountOfEnemies;i++)
	{
		Enemy enemy;
		enemies.push_back(enemy);
	}



	DisplayRoomTitles(RoomIndex + 1);
	std::cout << "You have entered the first room!\n\n";
	std::cout << amountOfEnemies << " Enemies has appeard\n\n";

	EnterToContinue();


}