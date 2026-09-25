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
		if (YesOrNoQuestion("Wanna enter the first room? "))
		{
			Room::allRooms[0].EnterRoom(0);
		}

		//Room::allRooms[0].EnterRoom();

		//rum logik
		//fråga vill du gå in i rum 1?
	}
}



