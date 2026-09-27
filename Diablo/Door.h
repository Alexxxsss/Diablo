#pragma once
#include <string>
#include <iostream>
#include <vector>
class Room;


class Door
{
private:
	Room* aRoom;

public:

	Door(Room* aRoom);

};