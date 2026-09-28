#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Enemy.h" 
#include "Door.h"
//class Door;
class Player;

//class Enemy;

class Room
{
public:
	static Room allRooms[5];

	bool hasBeenHere = false;
	int amountOfEnemies = 1;
	int amountOfDoores = 1;
	int roomIndex = 1;

	Room(int aRoomIndex);
	void EnterRoom(Player& aPlayer, Room aRecentRoom = { 3817 });
	std::vector<Door> doors;
	std::vector<Enemy> enemies;
	void DisplayRoomMenu(Player& aPlayer, Room& aRecentRoom);
	bool EnemyBattle(Player& aPlayer);
};
inline Room Room::allRooms[5] = { Room(0), Room(1), Room(2), Room(3), Room(4) };
