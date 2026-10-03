#include <iostream>
#include <string>
#include <random>
#include "Main.h"
#include "Room.h"

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
	std::cout << "Defence: " << aPlayer.GetDefence() << "\n\n\n";

	SetColor(33);
	std::cout << "Inventory: \n";
	ResetColor();
	if (aPlayer.myCurrentLoot.size() != 0) 
	{
		int index = 0;
		for (LootObject loot : aPlayer.myCurrentLoot)
		{
			index += 1;
			std::cout << index << ": " << loot.lootName<< " : " << loot.lootDescription << "\n";

		}
	}
	else 
	{
		std::cout << "Inventory is empty...\n";
	}
	
}

void PrintDiabloLogo()
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

void DisplayRoomTitles(int aRoomIndex)
{
	SetColor(31);
	switch (aRoomIndex)
	{
	case 0:
		std::cout << " ____   ___   ___  __  __   ___  \n";
		std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  | / _ \\ \n";
		std::cout << "| |_) | | | | | | | |\\/| || | | |\n";
		std::cout << "|  _ <| |_| | |_| | |  | || |_| |\n";
		std::cout << "|_| \\_\\\\___/ \\___/|_|  |_| \\___/ \n\n";
		break;
	case 1:
		std::cout << " ____   ___   ___  __  __   _ \n";
		std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  | / |\n";
		std::cout << "| |_) | | | | | | | |\\/| | | |\n";
		std::cout << "|  _ <| |_| | |_| | |  | | | |\n";
		std::cout << "|_| \\_\\\\___/ \\___/|_|  |_| |_|\n\n";
		break;
	case 2:
		std::cout << " ____   ___   ___  __  __  ____  \n";
		std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  ||___ \\ \n";
		std::cout << "| |_) | | | | | | | |\\/| |  __) |\n";
		std::cout << "|  _ <| |_| | |_| | |  | | / __/ \n";
		std::cout << "|_| \\_\\\\___/ \\___/|_|  |_||_____|\n\n";
		break;
	case 3:
		std::cout << " ____   ___   ___  __  __  _____ \n";
		std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  ||___ / \n";
		std::cout << "| |_) | | | | | | | |\\/| | |_ \\ \n";
		std::cout << "|  _ <| |_| | |_| | |  | |___) |\n";
		std::cout << "|_| \\_\\\\___/ \\___/|_|  |_|____/ \n\n";
		break;
	case 4:
		std::cout << " ____   ___   ___  __  __   _  _   \n";
		std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  | | || |  \n";
		std::cout << "| |_) | | | | | | | |\\/| | | || |_ \n";
		std::cout << "|  _ <| |_| | |_| | |  | | |__   _|\n";
		std::cout << "|_| \\_\\\\___/ \\___/|_|  |_|    |_|  \n\n";
		break;
	case 5:
		std::cout << " ____   ___   ___  __  __  ____  \n";
		std::cout << "|  _ \\ / _ \\ / _ \\|  \\/  || ___| \n";
		std::cout << "| |_) | | | | | | | |\\/| ||___ \\ \n";
		std::cout << "|  _ <| |_| | |_| | |  | |___) |\n";
		std::cout << "|_| \\_\\\\___/ \\___/|_|  |_|____/  \n\n";
		break;
	}
	ResetColor();
}

void WaitForEnterToContinue()
{
	std::cout << "\n";
	system("pause");
	system("cls");
}

bool CheckIfYouBeenToAllRooms()
{
	for (const Room& room : Room::allRooms)
	{
		if (!room.GetHasBeenHere())
		{
			return false;
		}
	}
	return true;
}

void SetColor(int aTextColor)
{
	std::cout << "\033[" << aTextColor << "m";
}

void ResetColor()
{
	std::cout << "\033[0m";
}

void DisplayChoiceBox(int aChoice, bool aIsInt)
{
	if (aIsInt)
	{
		std::cout << "\033[32m[\033[31m" << aChoice << "\033[32m]";
	}
	else
	{
		std::cout << "\033[32m[\033[31m" << static_cast<char>(aChoice) << "\033[32m]";
	}
	ResetColor();
}

void CheckForInputFails(int aInput, int aMinInput, int aMaxInput)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Cant input that!.\n";
	}

	if (aInput < aMinInput || aInput > aMaxInput)
	{
		std::cout << "Cant input that!.\n";
	}
}

bool AskYesOrNoQuestion(std::string aQuestion, std::string aPositiveAlternative, std::string aNegativeAlternative)
{
	int menuChoice = 0;

	while (true)
	{
		std::cout << aQuestion << "\n";

		DisplayChoiceBox('1');
		std::cout << " " << aPositiveAlternative << "\n";

		DisplayChoiceBox('2');
		std::cout << " " << aNegativeAlternative << "\n";

		DisplayChoiceBox('x');
		std::cout << ": ";

		std::cin >> menuChoice;
		CheckForInputFails(menuChoice, 1, 2);

		if (menuChoice == 1)
		{
			return true;
		}
		else if (menuChoice == 2)
		{
			return false;
		}
	}
}

int AskMultipleChoiceQuestion(int aMinValue, int aMaxValue, std::vector<std::string> aAllChoices)
{
	int menuChoice = 0;

	while (true)
	{
		for (int i = aMinValue; i < aMaxValue; i++)
		{
			DisplayChoiceBox(static_cast<char>(i));
			std::cout << " " << aAllChoices[i] << "\n";
		}

		std::cin >> menuChoice;
		CheckForInputFails(menuChoice, 1, 2);

		return menuChoice;
	}
}

int RandomizeInt(int aMinInclusive, int aMaxInclusive)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(aMinInclusive, aMaxInclusive);
	return distrib(gen);
}