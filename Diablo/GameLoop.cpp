#include "Main.h"

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

	Room room;
	Room room;
	Room room;
	Room room;

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
		YesOrNoQuestion("Wanna enter the first room? ");

		

		//rum logik
		//fråga vill du gå in i rum 1?
	}
}



