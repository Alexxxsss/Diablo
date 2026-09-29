#include "Main.h"
#include "Room.h"

#include <iostream>

void GameLoop(Player &aPlayer)
{
	//Meny

	//Loop
	//	Rum
	//	Dörr
	//	Attack
	//	---->
	
	//Name
	if (!YesOrNoQuestion("Wanna cheat by having nearly infinite hp?", "NO", "YES"))
	{
		aPlayer.SetPlayerHealthForCheats(1000000);
	}

	if (!YesOrNoQuestion("Wanna cheat by having nearly infinite damage?", "NO", "YES"))
	{
		aPlayer.SetPlayerDamageForCheats(1000000);
	}
	system("cls");
	DisplayPregameOptions(aPlayer);
	DisplayStatsInMenu(aPlayer);

	

	while (true)
	{
		system("cls");


		bool runGame = Menu(aPlayer);
		if (runGame == false)
		{
			break;
		}
		
		system("cls");
		Diablo();
		std::cout << "Hi " << aPlayer.GetPlayerName() << ", welcome to ";

		SetColor(31);
		std::cout << "Diablo!";
		ResetColor();

		std::cout << " to win the game you need to \nmake your way to the last room ";

		SetColor(31);
		std::cout << "(ROOM 5)";
		ResetColor();

		std::cout << " and kill all \nthe enemies to escape the dungeon and win\n\n";
		if (YesOrNoQuestion("Wanna enter the first room? "))
		{
			Room::allRooms[0].EnterRoom(aPlayer);
		}

		//Room::allRooms[0].EnterRoom();

		//rum logik
		//fråga vill du gå in i rum 1?
	}
}

void DisplayPregameOptions(Player& aPlayer)
{
	std::string playerName;
	while (true)
	{
		Diablo();
		std::cout << "Whats your name? (a name between 2 and 12 characters):\n";
		std::cin >> playerName;

		if (playerName.size() < 13 && playerName.size() > 1)
		{
			aPlayer.SetPlayerName(playerName);
			break;

		}
		system("cls");
	}
}

