#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Enemy.h" 

class Door;
class Player;

//class Enemy;

class Room
{
public:
	static Room allRooms[5];

	Room();
	void EnterRoom(int aRoomIndex, Player& aPlayer);
	std::vector<Door> doors;
	std::vector<Enemy> enemies;

	bool EnemyBattle(Player& aPlayer, int& aAmountOfEnemies, int RoomIndex);
};