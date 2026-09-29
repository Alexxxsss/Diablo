#include <iostream>
#include "Main.h"
#include "Door.h"
#include "Room.h"



Door::Door(Room *aRoom, Room* aRoomOther, bool aDoorIsLocked)
{
	this->aRoom = aRoom;
	this->aRoomOther = aRoomOther;
	this->doorIsLocked = aDoorIsLocked;
}