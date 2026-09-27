#include <iostream>
#include "Main.h"
#include <vector>
#include "Room.h"
#include "Door.h"
#include "Enemy.h"


Room Room::allRooms[5];

Room::Room()
{
	
}

void Room::EnterRoom(int aRoomIndex, Player &aPlayer)
{
	system("cls");

	int amountOfEnemies = RandomizeInt(1, 3);
	int amountOfDoores = RandomizeInt(1, 3);

	
	for (int i = 0;i < amountOfDoores;i++)		// Adding the randomized amount of doors to the vector
	{
		int roomIndex = RandomizeInt(0, 4);		

		Door door(&allRooms[roomIndex]);
		doors.push_back(door);
	}
	for (int i = 0;i < amountOfEnemies;i++)		// Adding the randomized amount of Enemies to the vector
	{
		Enemy enemy;
		enemies.push_back(enemy);
	}


	DisplayRoomTitles(aRoomIndex + 1);
	std::cout << "You have entered the first room!\n\n";
	std::cout << amountOfEnemies << " Enemies has appeard\n\n";

	for (int i = 0; i < amountOfDoores;i++) 
	{
		//std::cout << "Door " << i+1 << "\n";
	}
	EnterToContinue();
	EnemyBattle(aPlayer, amountOfEnemies, aRoomIndex);

}


void Room::EnemyBattle(Player& aPlayer, int &aAmountOfEnemies, int aRoomIndex)
{
	int menuChoise = 0;
	while (true) 
	{
		system("cls");

		DisplayRoomTitles(aRoomIndex + 1);

		SetColor(32);
		std::cout << "Your Health is " << aPlayer.GetCurrentHealth() << "\n\n";
		for (int i = 0; i < aAmountOfEnemies; i++)
		{
			if (enemies[i].GetHealth() <= 0)
			{
				SetColor(31);
				std::cout << "Enemy " << i + 1 << " Has " << enemies[i].GetHealth() << "HP\n";
			}
			else
			{
				SetColor(32);
				std::cout << "Enemy " << i + 1 << " Has " << enemies[i].GetHealth() << "HP\n";
			}
		}
		ResetColor();

		std::cout << "\nChoose what enemy to attack first: \n";
		std::cin >> menuChoise;	//	Asking for menu Input
		CheckForInputFails(menuChoise, 1, aAmountOfEnemies);
		
		for (int i = 1; i < aAmountOfEnemies+1; i++)
		{
			if (i == menuChoise) 
			{
				enemies[i - 1].TakeDamage(aPlayer.GetAttackValue());
			}
		}


	}
}