#include "Main.h"

#include <iostream>


bool Menu(Player& aPlayer)
{
	//	Locala Variabler
	int menuChoise = 0;

	while (true)
	{
		Diablo();


		MenuChoiseBoxes('1');
		std::cout << " PLAY\n";

		MenuChoiseBoxes('2');
		std::cout << " STATS\n";

		MenuChoiseBoxes('3');
		std::cout << " QUIT\n";

		MenuChoiseBoxes('x');
		std::cout << ": ";


		//SetColor(31);			//	Input Color
		std::cin >> menuChoise;	//	Asking for menu Input
		//ResetColor();			//	Reset Color

		MenuStates menuState = GetMenuChoiseState(menuChoise);



		switch (menuState)
		{
		case MenuStates::Play:
		{
			return true;
			break;
		}
		case MenuStates::Stats:
		{
			DisplayStatsInMenu(aPlayer);
			break;
		}
		case MenuStates::Quit:
		{
			return false;
			break;
		}
		}
	}
	

}


MenuStates GetMenuChoiseState(int& aChoise)
{
	switch (aChoise)
	{
		case 1:
		{
			return MenuStates::Play;
			break;
		}
		case 2:
		{
			return MenuStates::Stats;
			break;
		}
		case 3:
		{
			return MenuStates::Quit;
			break;
		}
	}

	return MenuStates::Quit;
}

void DisplayStatsInMenu(Player& aPlayer)
{
	system("cls");
	Diablo();
	ShowStats(aPlayer);

	EnterToContinue();
}