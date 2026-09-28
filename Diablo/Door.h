#pragma once
#include <string>
#include <iostream>
#include <vector>
class Room;


class Door
{
private:

public:
	//Room GetRoom() { return aRoom; }
	Room* aRoom = nullptr;

	Door(Room* aRoom);

};