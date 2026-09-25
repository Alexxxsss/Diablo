#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Enemy.h" 
class Door;
//class Enemy;

class Room
{
public:
	static Room allRooms[5];

	Room();
	void EnterRoom(int RoomIndex);
	std::vector<Door> doors;
	std::vector<Enemy> enemies;
};