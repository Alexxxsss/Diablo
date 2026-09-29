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
	void EnterRoom(Player& aPlayer);
	std::vector<Door> doors;
	std::vector<Enemy> enemies;
	void DisplayRoomMenu(Player& aPlayer);
	bool EnemyBattle(Player& aPlayer);
};
