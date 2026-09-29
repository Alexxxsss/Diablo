#pragma once
#include <string>
#include <iostream>
#include <vector>
class Room;


class Door
{
private:

public:
	static Door allDoors[5];
	Room* aRoom = nullptr;
	Room* aRoomOther = nullptr;
	bool doorIsLocked;
	Door(Room* aRoom, Room* aRoomOther, bool aDoorIsLocked = false);

};

