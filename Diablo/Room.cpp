#include <iostream>
#include "Main.h"
#include <vector>
#include "Room.h"
#include "Door.h"
#include "Enemy.h"


//Room Room::allRooms[5];

Room::Room(int aRoomIndex)
{
	roomIndex = aRoomIndex;
}

void Room::EnterRoom(Player &aPlayer, Room aRecentRoom)
{

	system("cls");
	//std::cout << "\n\n" << aRecentRoom.roomIndex+1 << "\n\n";
	if (hasBeenHere == false)
	{
		amountOfEnemies = RandomizeInt(1, 3);
		amountOfDoores = RandomizeInt(1, 2);
		

		for (int i = 0;i < amountOfDoores;i++)		// Adding the randomized amount of doors to the vector
		{
			//int roomIndex = RandomizeInt(0, 4);
			
			if (CheckIfYouBeenToAllRooms())
			{
				for (Room room : Room::allRooms)
				{
					if (room.hasBeenHere == false)
					{
						Door door(&room);
						doors.push_back(door);
					}

				}
			}
			else
			{
				Door door(&allRooms[RandomizeInt(0, 4)]);
				doors.push_back(door);
			}

				
			

			
		}
		for (int i = 0;i < amountOfEnemies;i++)		// Adding the randomized amount of Enemies to the vector
		{
			Enemy enemy;
			enemies.push_back(enemy);
		}

		hasBeenHere = true;
	}
	


	DisplayRoomTitles(roomIndex + 1);
	std::cout << "You have entered the first room!\n\n";
	std::cout << amountOfEnemies << " Enemies has appeard\n\n";

	for (int i = 0; i < amountOfDoores;i++) 
	{
		//std::cout << "Door " << i+1 << "\n";
	}
	EnterToContinue();
	if (EnemyBattle(aPlayer) == false)
	{
		std::cout << "YOU DIED!";
		return;
	}

	system("pause");

	DisplayRoomMenu(aPlayer, aRecentRoom);
	
}

void Room::DisplayRoomMenu(Player& aPlayer, Room &aRecentRoom)
{
	int menuChoise = 0;

	system("cls");

	while (true)
	{
		DisplayRoomTitles(roomIndex + 1);

		std::cout << "\nWhat do you wanna do?\n\n";
		MenuChoiseBoxes('0');
		std::cout << " STATS\n";


		for (int i = 0; i < amountOfDoores; i++)
		{
			MenuChoiseBoxes((i + 1), true);
			std::cout << " Door " << i + 1 << " --> " << "Room " << doors[i].aRoom->roomIndex+1 << "\n";
			
		}
		if (aRecentRoom.roomIndex != 3817)
		{
			MenuChoiseBoxes((amountOfDoores + 1), true);
			std::cout << " Back to " << "-> " << "Room " << aRecentRoom.roomIndex + 1 << "\n";   //MÅSTE FIXA DÖRR TBXXX
		}
		

		MenuChoiseBoxes('x');
		std::cout << ": ";

		std::cin >> menuChoise;
		CheckForInputFails(menuChoise, 0, amountOfDoores);

		for (int i = 0; i < menuChoise+1; i++)
		{
			if (i == 0 && menuChoise == i)
			{
				system("cls");
				DisplayRoomTitles(roomIndex + 1);

				ShowStats(aPlayer);
				EnterToContinue();
				break;
			}
			else if (amountOfDoores + 1 == menuChoise && menuChoise == i)
			{
				aRecentRoom.EnterRoom(aPlayer, *this); //Går till förra rummet
			}
			else if (i == menuChoise)
			{
				doors[menuChoise - 1].aRoom->EnterRoom(aPlayer, *this);
				return;
			}
		}

	}
	
}

bool Room::EnemyBattle(Player& aPlayer)
{
	int menuChoise = 0;
	while (true) 
	{

		

		system("cls");

		//-------Display room title and HP for enemy and Player-------//
		DisplayRoomTitles(roomIndex + 1);
		SetColor(32);
		std::cout << "Your Health is " << aPlayer.GetCurrentHealth() << "\n\n";
		for (int i = 0; i < amountOfEnemies; i++)
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
		//-----------------------------------------------------------//



		//-------Check if battle is done and results-------//
		bool enemyIsAlive = false;
		if (aPlayer.GetCurrentHealth() <= 0)
		{
			return false;
		}
		for (int i = 1; i < amountOfEnemies + 1; i++)
		{
			if (enemies[i - 1].GetHealth() > 0)
			{
				enemyIsAlive = true;
			}
		}
		if (enemyIsAlive == false)
		{
			return true;
		}
		//--------------------------------------------------//



		std::cout << "\nChoose what enemy to attack first: \n";
		std::cin >> menuChoise;	//	Asking for menu Input
		CheckForInputFails(menuChoise, 1, amountOfEnemies);
		
		for (int i = 1; i < amountOfEnemies+1; i++)
		{
			if (i == menuChoise) 
			{
				enemies[i - 1].TakeDamage(aPlayer.GetAttackValue());
			}
		}


	}

	return true;
}
