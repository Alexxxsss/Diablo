#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Door.h"

class Player;

class Room
{
public:
	static Room allRooms[5];

	Room(int aRoomIndex);

	void EnterRoom(Player& aPlayer);
	void DisplayRoomMenu(Player& aPlayer);
	bool ExecuteBattle(Player& aPlayer);

	int GetRoomIndex() const { return myRoomIndex; }
	void SetRoomIndex(int aRoomIndex) { myRoomIndex = aRoomIndex; }

	bool GetHasBeenHere() const { return myHasBeenHere; }
	void SetHasBeenHere(bool aHasBeenHere) { myHasBeenHere = aHasBeenHere; }

	int GetAmountOfEnemies() const { return myAmountOfEnemies; }
	void SetAmountOfEnemies(int aAmount) { myAmountOfEnemies = aAmount; }

	int GetAmountOfDoors() const { return myAmountOfDoors; }
	void SetAmountOfDoors(int aAmount) { myAmountOfDoors = aAmount; }

	std::vector<Door*>& GetDoors() { return myDoors; }
	std::vector<Enemy>& GetEnemies() { return myEnemies; }

private:
	bool myHasBeenHere = false;
	int myAmountOfEnemies = 1;
	int myAmountOfDoors = 1;
	int myRoomIndex = 1;

	std::vector<Door*> myDoors;
	std::vector<Enemy> myEnemies;
};