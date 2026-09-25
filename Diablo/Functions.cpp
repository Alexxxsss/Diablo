#include <iostream>
#include <string>
#include "Main.h"
#include <random> 

void ShowStats(Player& aPlayer)
{
	SetColor(33);
	std::cout << "Main Stats: \n";
	ResetColor();
	std::cout << "Strength: " << aPlayer.GetStrength() << "\n";
	std::cout << "Agility: " << aPlayer.GetAgility() << "\n";
	std::cout << "Physical: " << aPlayer.GetPhysical() << "\n";

	SetColor(33);
	std::cout << "\nSecondary Stats (based on the main ones): \n";
	ResetColor();
	std::cout << "MaxHealth: " << aPlayer.GetMaxHealth() << "\n";
	std::cout << "AttackValue: " << aPlayer.GetAttackValue() << "\n";
	std::cout << "WeightCapacity: " << aPlayer.GetWeightCapacity() << "\n";
	std::cout << "Defence: " << aPlayer.GetDefence() << "\n";
}

void Diablo()
{
	SetColor(31);
	std::cout << " ______   ___   _______  _______  ___      _______ \n";
	std::cout << "|      | |   | |   _   ||  _    ||   |    |       |\n";
	std::cout << "|  _    ||   | |  |_|  || |_|   ||   |    |   _   |\n";
	std::cout << "| | |   ||   | |       ||       ||   |    |  | |  |\n";
	std::cout << "| |_|   ||   | |       ||  _    ||   |___ |  |_|  |\n";
	std::cout << "|       ||   | |   _   || |_|   ||       ||       |\n";
	std::cout << "|______| |___| |__| |__||_______||_______||_______|\n\n";
	ResetColor();
}

void DisplayRoomTitles(int aRoom)
{
	SetColor(31);
	switch (aRoom)
	{
		case 0:
		{
			// ROOM 0

			std::cout << " ____   ___   ___  __  __   ___  \n";
			std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  | / _ \\ \n";
			std::cout << "| |_) | | | | | | | |\\/| || | | |\n";
			std::cout << "|  _ <| |_| | |_| | |  | || |_| |\n";
			std::cout << "|_| \\_\\\\___/ \\___/|_|  |_| \\___/ \n\n";
			break;
		}
		case 1:
		{
			// ROOM 1
			std::cout << " ____   ___   ___  __  __   _ \n";
			std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  | / |\n";
			std::cout << "| |_) | | | | | | | |\\/| | | |\n";
			std::cout << "|  _ <| |_| | |_| | |  | | | |\n";
			std::cout << "|_| \\_\\\\___/ \\___/|_|  |_| |_|\n\n";
			break;
		}
		case 2:
		{
			// ROOM 2
			std::cout << " ____   ___   ___  __  __  ____  \n";
			std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  |/ ___| \n";
			std::cout << "| |_) | | | | | | | |\\/| |___ \\ \n";
			std::cout << "|  _ <| |_| | |_| | |  | |___) |\n";
			std::cout << "|_| \\_\\\\___/ \\___/|_|  |_|____/ \n\n";
			break;
		}
		case 3:
		{
			// ROOM 3
			std::cout << " ____   ___   ___  __  __  _____ \n";
			std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  ||___ / \n";
			std::cout << "| |_) | | | | | | | |\\/| | |_ \\ \n";
			std::cout << "|  _ <| |_| | |_| | |  | |___) |\n";
			std::cout << "|_| \\_\\\\___/ \\___/|_|  |_|____/ \n\n";
			break;
		}
		case 4:
		{
			// ROOM 4
			std::cout << " ____   ___   ___  __  __   _  _   \n";
			std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  | | || |  \n";
			std::cout << "| |_) | | | | | | | |\\/| | | || |_ \n";
			std::cout << "|  _ <| |_| | |_| | |  | | |__   _|\n";
			std::cout << "|_| \\_\\\\___/ \\___/|_|  |_|    |_|  \n\n";
			break;
		}
		case 5:
		{
			// ROOM 5
			std::cout << " ____   ___   ___  __  __  ____  \n";
			std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  || ___| \n";
			std::cout << "| |_) | | | | | | | |\\/| ||___ \\ \n";
			std::cout << "|  _ <| |_| | |_| | |  | |___) |\n";
			std::cout << "|_| \\_\\\\___/ \\___/|_|  |_|____/  \n\n";
			break;
		}

	}
	ResetColor();
	
}

void EnterToContinue()
{
	std::cout << "\n";

	system("pause");

	system("cls");
}



/// <summary>
///	31: Röd
///	32: Grön
///	33: Gul
///	34: Blå
///	35: Lila
///	37: Vit
/// </summary>
void SetColor(int aTextColor)
{
	std::cout << "\033[" << aTextColor << "m";
}
void ResetColor() 
{ 
	std::cout << "\033[0m"; 
}

void MenuChoiseBoxes(char aChoise)
{
	std::cout << "\033[" << 32 << "m" << "[" << "\033[" << 31 << "m" << aChoise << "\033[" << 32 << "m" << "]";
	//SetColor(32);
	ResetColor();
}

void CheckForInputFails(int input, int aMinInput, int aMaxInput)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Felaktig inmatning!.\n";
	}

	if (input < aMinInput || input >aMaxInput)
	{
		std::cout << "Felaktig inmatning!.\n";
	}
}

bool YesOrNoQuestion(std::string aQuestion, std::string aPositiveAlternative, std::string aNegativeAlternative)
{
	int menuChoise = 0;

	while (true)
	{
		std::cout << aQuestion << "\n";


		MenuChoiseBoxes('1');
		std::cout << " " << aPositiveAlternative << "\n";

		MenuChoiseBoxes('2');
		std::cout << " " << aNegativeAlternative << "\n";

		MenuChoiseBoxes('x');
		std::cout << ": ";

		//SetColor(31);			//	Input Color
		std::cin >> menuChoise;	//	Asking for menu Input
		CheckForInputFails(menuChoise,1,2);
		//ResetColor();			//	Reset Color

		if (menuChoise == 1)
		{
			return true;
		}
		else if (menuChoise == 2)
		{
			return false;
		}
		else
		{
			//ngt fel
		}
	}
}

int RandomizeInt(int aMinExclusive, int aMaxNonExclusive)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(aMinExclusive, aMaxNonExclusive);


	return distrib(gen);
}