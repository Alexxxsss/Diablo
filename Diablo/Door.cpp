#include "Door.h"
#include "Room.h"

Door Door::allDoors[5] = {
	Door(&Room::allRooms[0], &Room::allRooms[1]),
	Door(&Room::allRooms[0], &Room::allRooms[2], true),
	Door(&Room::allRooms[1], &Room::allRooms[3]),
	Door(&Room::allRooms[1], &Room::allRooms[4], true),
	Door(&Room::allRooms[2], &Room::allRooms[4])
};

Door::Door(Room* aRoomA, Room* aRoomB, bool aIsLocked)
{
	myRoomA = aRoomA;
	myRoomB = aRoomB;
	myIsLocked = aIsLocked;
}