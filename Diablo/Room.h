#pragma once
#include <string>
#include <iostream>
#include <vector>
class Door;

class Room
{
public:
	static Room allRooms[5];

	Room();
	void EnterRoom();
	std::vector<Door> doors;
};