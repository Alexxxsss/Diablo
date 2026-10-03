#include "Main.h"
#include <iostream>

bool RunMenu(Player& aPlayer)
{
	int menuChoice = 0;

	while (true)
	{
		while (true)
		{
			PrintDiabloLogo();

			DisplayChoiceBox('1');
			std::cout << " PLAY\n";

			DisplayChoiceBox('2');
			std::cout << " STATS/INVENTORY\n";

			DisplayChoiceBox('3');
			std::cout << " QUIT\n";

			DisplayChoiceBox('x');
			std::cout << ": ";

			std::cin >> menuChoice;
			CheckForInputFails(menuChoice, 1, 3);
			if (menuChoice <= 3 && menuChoice > 0)
			{
				break;
			}
		}

		MenuStates menuState = GetMenuChoiceState(menuChoice);

		switch (menuState)
		{
		case MenuStates::Play:
			return true;
		case MenuStates::Stats:
			DisplayStatsInMenu(aPlayer);
			break;
		case MenuStates::Quit:
			return false;
		}
	}
}

MenuStates GetMenuChoiceState(int& aChoice)
{
	switch (aChoice)
	{
	case 1:
		return MenuStates::Play;
	case 2:
		return MenuStates::Stats;
	case 3:
		return MenuStates::Quit;
	}

	return MenuStates::Quit;
}

void DisplayStatsInMenu(Player& aPlayer)
{
	system("cls");
	PrintDiabloLogo();
	ShowStats(aPlayer);
	WaitForEnterToContinue();
}