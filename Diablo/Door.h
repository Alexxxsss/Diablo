#pragma once
#include <vector>

class Room;

class Door
{
public:
	static Door allDoors[5];

	Door(Room* aRoomA, Room* aRoomB, bool aIsLocked = false);

	// Getters and Setters
	Room* GetRoomA() const { return myRoomA; }
	void SetRoomA(Room* aRoomA) { myRoomA = aRoomA; }

	Room* GetRoomB() const { return myRoomB; }
	void SetRoomB(Room* aRoomB) { myRoomB = aRoomB; }

	bool GetIsLocked() const { return myIsLocked; }
	void SetIsLocked(bool aIsLocked) { myIsLocked = aIsLocked; }

private:
	Room* myRoomA = nullptr;
	Room* myRoomB = nullptr;
	bool myIsLocked = false;
};