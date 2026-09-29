#include <iostream>
#include "Main.h"
#include <vector>
#include "Room.h"
#include "Door.h"
#include "Enemy.h"

Room Room::allRooms[5] = { Room(0), Room(1), Room(2), Room(3), Room(4) };

Door Door::allDoors[5] = {
	Door(&Room::allRooms[0], &Room::allRooms[1]),
	Door(&Room::allRooms[0], &Room::allRooms[2], true),
	Door(&Room::allRooms[1], &Room::allRooms[3]),
	Door(&Room::allRooms[1], &Room::allRooms[4], true),
	Door(&Room::allRooms[2], &Room::allRooms[4])
};

Room::Room(int aRoomIndex)
{
	roomIndex = aRoomIndex;
}

void Room::EnterRoom(Player &aPlayer)
{
	system("cls");

	DisplayRoomTitles(roomIndex + 1);


	//std::cout << "\n\n" << aRecentRoom.roomIndex+1 << "\n\n";
	if (hasBeenHere == false)
	{
		amountOfEnemies = RandomizeInt(1, 3);
		
		
		for (Door door : Door::allDoors)
		{
			if (door.aRoom->roomIndex == roomIndex || door.aRoomOther->roomIndex == roomIndex)
			{
				doors.push_back(door);
			}
		}

		for (int i = 0;i < amountOfEnemies;i++)		// Adding the randomized amount of Enemies to the vector
		{
			Enemy enemy;
			enemies.push_back(enemy);
		}
		std::cout << "You have entered a new room!\n\n";
		hasBeenHere = true;
	}
	


	std::cout << "Be careful " << aPlayer.GetPlayerName() << ", This room may contain enemies be alert!\n\n";
	//std::cout << amountOfEnemies << " Enemies has appeard\n\n";

	for (int i = 0; i < amountOfDoores;i++) 
	{
		//std::cout << "Door " << i+1 << "\n";
	}
	EnterToContinue();
	if (EnemyBattle(aPlayer) == false)
	{
		system("cls");
		std::cout << "YOU DIED " << aPlayer.GetPlayerName() << "!\nByeBye!";
		EnterToContinue();
		return;
	}

	system("pause");


	if (roomIndex == 4)
	{
		std::cout << aPlayer.GetPlayerName() << ", You have escaped the ";
		SetColor(31);
		std::cout << "Diablo";
		ResetColor();
		std::cout << " dungeon, congrats!";

		EnterToContinue();
	}
	else
	{
		DisplayRoomMenu(aPlayer);
	}
	
}

void Room::DisplayRoomMenu(Player& aPlayer)
{
	int menuChoise = 0;

	system("cls");

	while (true)
	{
		system("cls");

		while (true)
		{
			DisplayRoomTitles(roomIndex + 1);

			std::cout << "\nWhat do you wanna do " << aPlayer.GetPlayerName() << "?\n\n";
			MenuChoiseBoxes('0');
			std::cout << " STATS\n";


			for (int i = 0; i < doors.size(); i++)
			{
				MenuChoiseBoxes((i + 1), true);
				if (doors[i].aRoom->roomIndex != roomIndex)
				{
					std::cout << " Door " << i + 1 << " --> " << "Room " << doors[i].aRoom->roomIndex + 1 << "\n";
				}
				else if (doors[i].aRoomOther->roomIndex != roomIndex)
				{
					std::cout << " Door " << i + 1 << " --> " << "Room " << doors[i].aRoomOther->roomIndex + 1 << "\n";
				}

			}
			std::cout << "\n";



			MenuChoiseBoxes('x');
			std::cout << ": ";

			std::cin >> menuChoise;
			CheckForInputFails(menuChoise, 0, amountOfDoores + 1);

			if (menuChoise < amountOfDoores+2 && menuChoise > -1) 
			{
				break;
			}
		}
		


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
			else if (i == menuChoise)
			{
				if (doors[menuChoise - 1].aRoom->roomIndex != roomIndex)
				{
					if (doors[menuChoise - 1].doorIsLocked == true)
					{
						std::cout << "This door is locked!\n";
						if (YesOrNoQuestion("Wanna pick the lock (choose NO to get choice to destroy the door)?"))
						{
							while (true)
							{
								int randomizedNumberForLockPick = RandomizeInt(0, 10);
								if (randomizedNumberForLockPick <= aPlayer.GetAgility())
								{
									doors[menuChoise - 1].doorIsLocked = false;
									std::cout << "Lock picked!";
									EnterToContinue();
									doors[menuChoise - 1].aRoom->EnterRoom(aPlayer);
									return;
									break;
								}
								else
								{
									if (YesOrNoQuestion("You failed the pick, maybe to low agility? Try Again?"))
									{
										continue;
									}
									else
									{
										system("cls");   
										break;
									}
								}
							}
							
						}

						if (YesOrNoQuestion("Wanna destroy the door?"))
						{
							while (true)
							{
								int randomizedNumberForDoorBreak = RandomizeInt(0, 10);
								if (randomizedNumberForDoorBreak <= aPlayer.GetAgility())
								{
									doors[menuChoise - 1].doorIsLocked = false;
									std::cout << "Door broken!";
									EnterToContinue();
									doors[menuChoise - 1].aRoom->EnterRoom(aPlayer);
									return;
									break;
								}
								else
								{
									if (YesOrNoQuestion("You failed the door break, maybe to low strength? Try Again?"))
									{
										continue;
									}
									else
									{
										system("cls");
										break;
									}
								}
							}

						}
					}
					else
					{
						doors[menuChoise - 1].aRoom->EnterRoom(aPlayer);
					}

				}
				else if (doors[menuChoise - 1].aRoomOther->roomIndex != roomIndex)
				{
					if (doors[menuChoise - 1].doorIsLocked == true)
					{
						std::cout << "This door is locked!\n";
						if (YesOrNoQuestion("Wanna pick the lock (choose NO to get choice to destroy the door)?"))
						{
							while (true) 
							{
								int randomizedNumberForLockPick = RandomizeInt(0, 10);
								if (randomizedNumberForLockPick <= aPlayer.GetAgility()) 
								{
									doors[menuChoise - 1].doorIsLocked = false;
									std::cout << "Lock picked!";
									EnterToContinue();
									doors[menuChoise - 1].aRoomOther->EnterRoom(aPlayer);
									return;
									break;
								}
								else 
								{
									if (YesOrNoQuestion("You failed the pick, maybe to low agility? Try Again?")) 
									{
										continue;
									}
									else 
									{
										system("cls");
										break;
									}
								}
								
								
							}
							
						}

						if (YesOrNoQuestion("Wanna destroy the door?"))
						{
							while (true)
							{
								int randomizedNumberForDoorBreak = RandomizeInt(0, 10);
								if (randomizedNumberForDoorBreak <= aPlayer.GetStrength())
								{
									doors[menuChoise - 1].doorIsLocked = false;
									std::cout << "Door broken!";
									EnterToContinue();
									doors[menuChoise - 1].aRoomOther->EnterRoom(aPlayer);
									return;
									break;
								}
								else
								{
									if (YesOrNoQuestion("You failed the door break, maybe to low strength? Try Again?"))
									{
										continue;
									}
									else
									{
										system("cls");
										break;
									}
								}


							}

						}
					}
					else
					{
						doors[menuChoise - 1].aRoomOther->EnterRoom(aPlayer);
					}
				}

				//doors[menuChoise - 1].aRoom->EnterRoom(aPlayer, *this);
				
			}
		}
	}
	return;
	
}

bool Room::EnemyBattle(Player& aPlayer)
{
	int menuChoise = 0;
	while (true) 
	{

		

		system("cls");

		//-------Display room title and HP for enemy and Player-------//
		DisplayRoomTitles(roomIndex + 1);
		std::cout << "You are in battle! If you type wrong you miss your attack!\n\n";
		SetColor(32);
		std::cout << aPlayer.GetPlayerName() << "(you) Has " << aPlayer.GetCurrentHealth() << "HP\n\n";
		for (int i = 0; i < amountOfEnemies; i++)
		{
			if (enemies[i].GetHealth() <= 0)
			{
				MenuChoiseBoxes(i+1,true);
				SetColor(31);
				std::cout << " Enemy " << i + 1 << " Has " << enemies[i].GetHealth() << "HP\n";
			}
			else
			{
				MenuChoiseBoxes(i + 1, true);
				SetColor(32);
				std::cout << " Enemy " << i + 1 << " Has " << enemies[i].GetHealth() << "HP\n";
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

		int enemiesCombinedDamage = 0;
		for (Enemy enemy : enemies)
		{
			if (enemy.GetHealth() > 0)
			{
				enemiesCombinedDamage = enemiesCombinedDamage + enemy.GetDamage() - aPlayer.GetDefence();
			}
		}
		aPlayer.TakeDamage(enemiesCombinedDamage);

		if (aPlayer.GetAliveState() == false)
		{
			return false;
		}
	}

	return true;
}
