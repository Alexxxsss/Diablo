#include <iostream>
#include <vector>
#include "Main.h"
#include "Room.h"
#include "Door.h"
#include "Enemy.h"
struct LootObject;

Room Room::allRooms[5] = { Room(0), Room(1), Room(2), Room(3), Room(4) };

Room::Room(int aRoomIndex)
{
	myRoomIndex = aRoomIndex;
}

void Room::EnterRoom(Player& aPlayer)
{
	system("cls");

	DisplayRoomTitles(myRoomIndex + 1, aPlayer);
	if (!myHasBeenHere)
	{
		myAmountOfEnemies = RandomizeInt(1, 3);
		myAmountOfChests = RandomizeInt(0, 2);
		myAmountOfSpells = RandomizeInt(0, 1);
		myAmountOfLoot = RandomizeInt(1, 3);

		for (Door& door : Door::allDoors)
		{
			if (door.GetRoomA()->GetRoomIndex() == myRoomIndex || door.GetRoomB()->GetRoomIndex() == myRoomIndex)
			{
				myDoors.push_back(&door);
			}
		}

		for (int i = 0; i < myAmountOfEnemies; i++)
		{
			Enemy enemy;
			myEnemies.push_back(enemy);
		}
		for (int i = 0; i < myAmountOfChests; i++)
		{
			Chest chest;
			myChests.push_back(chest);
		}
		for (int i = 0; i < myAmountOfLoot; i++)
		{
			//LootObject loot;
			myLoot.push_back(ReturnRandomLoot(aPlayer));
		}
		for (int i = 0; i < myAmountOfSpells; i++)
		{
			//LootObject loot;
			mySpells.push_back(ReturnRandomSpell(aPlayer));
		}
		std::cout << "You have entered a new room!\n\n";
	}

	std::cout << "Be careful " << aPlayer.GetPlayerName() << ", This room may contain enemies be alert!\n\n";

	WaitForEnterToContinue();
	if (!ExecuteBattle(aPlayer))
	{
		system("cls");
		std::cout << "YOU DIED " << aPlayer.GetPlayerName() << "!\nByeBye!";
		WaitForEnterToContinue();
		return;
	}

	system("pause");
	//Loot logic
	
	if (AskYesOrNoQuestion("Do you want to look at the floor for Loot and chests, or maybe some spell?"))
	{
		for (LootObject &loot : myLoot)
		{
			std::string question = "Do you want to pick up " + static_cast<std::string>(loot.lootName);

			if (aPlayer.GetWeightCapacity() < aPlayer.CalculateInventoryWeight() + loot.weight)
			{
				std::cout << loot.lootName << " is to heavy for you inventory";
				continue;
			}
			
			if (AskYesOrNoQuestion(question))
			{
				aPlayer.myCurrentLoot.push_back(loot);
				aPlayer.RecalebrateStats();
			}
		}

		for (Chest& chest : myChests)
		{
			chest.OpenChest(aPlayer);
		}

		for (Spells& spell : mySpells)
		{
			std::string question = "Do you want to use the " + static_cast<std::string>(spell.spellName);


			if (AskYesOrNoQuestion(question))
			{
				aPlayer.myCurrentSpells.push_back(spell);
				aPlayer.RecalebrateSpells();
			}
		}
	}

	system("pause");

	myHasBeenHere = true;

	if (myRoomIndex == 4)
	{
		std::cout << aPlayer.GetPlayerName() << ", You have escaped the ";
		SetColor(31);
		std::cout << "Diablo";
		ResetColor();
		std::cout << " dungeon, congrats!";

		WaitForEnterToContinue();
	}
	else
	{
		DisplayRoomMenu(aPlayer);
	}
}

void Room::DisplayRoomMenu(Player& aPlayer)
{
	int menuChoice = 0;

	system("cls");

	while (true)
	{
		system("cls");

		while (true)
		{
			DisplayRoomTitles(myRoomIndex + 1, aPlayer);

			std::cout << "\nWhat do you wanna do " << aPlayer.GetPlayerName() << "?\n\n";
			DisplayChoiceBox('0');
			std::cout << " STATS/INVENTORY\n";

			for (size_t i = 0; i < myDoors.size(); i++)
			{
				DisplayChoiceBox(static_cast<int>(i + 1), true);
				if (myDoors[i]->GetRoomA()->GetRoomIndex() != myRoomIndex)
				{
					std::cout << " Door " << i + 1 << " --> " << "Room " << myDoors[i]->GetRoomA()->GetRoomIndex() + 1 << "\n";
				}
				else if (myDoors[i]->GetRoomB()->GetRoomIndex() != myRoomIndex)
				{
					std::cout << " Door " << i + 1 << " --> " << "Room " << myDoors[i]->GetRoomB()->GetRoomIndex() + 1 << "\n";
				}
			}
			std::cout << "\n";

			DisplayChoiceBox('x');
			std::cout << ": ";

			std::cin >> menuChoice;
			CheckForInputFails(menuChoice, 0, static_cast<int>(myDoors.size()));

			if (menuChoice <= static_cast<int>(myDoors.size()) && menuChoice >= 0)
			{
				break;
			}
		}

		if (menuChoice == 0)
		{
			system("cls");
			DisplayRoomTitles(myRoomIndex + 1, aPlayer);
			ShowStats(aPlayer);
			WaitForEnterToContinue();
			continue;
		}

		Door* selectedDoor = myDoors[menuChoice - 1];
		Room* targetRoom = (selectedDoor->GetRoomA()->GetRoomIndex() != myRoomIndex)
			? selectedDoor->GetRoomA()
			: selectedDoor->GetRoomB();

		if (selectedDoor->GetIsLocked())
		{
			std::cout << "This door is locked!\n";
			if (AskYesOrNoQuestion("Wanna pick the lock (choose NO to get choice to destroy the door)?"))
			{
				while (true)
				{
					int randomizedNumber = RandomizeInt(0, 10);
					if (randomizedNumber <= aPlayer.GetAgility())
					{
						selectedDoor->SetIsLocked(false);
						std::cout << "Lock picked!";
						WaitForEnterToContinue();
						aPlayer.RecalebrateSpellsAfterLeavingRoom();
						targetRoom->EnterRoom(aPlayer);
						return;
					}
					else
					{
						if (AskYesOrNoQuestion("You failed the pick, maybe to low agility? Try Again?"))
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

			if (AskYesOrNoQuestion("Wanna destroy the door?"))
			{
				while (true)
				{
					int randomizedNumber = RandomizeInt(0, 10);
					if (randomizedNumber <= aPlayer.GetStrength())
					{
						selectedDoor->SetIsLocked(false);
						std::cout << "Door broken!";
						WaitForEnterToContinue();
						aPlayer.RecalebrateSpellsAfterLeavingRoom();
						targetRoom->EnterRoom(aPlayer);
						return;
					}
					else
					{
						if (AskYesOrNoQuestion("You failed the door break, maybe to low strength? Try Again?"))
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
			aPlayer.RecalebrateSpellsAfterLeavingRoom();
			targetRoom->EnterRoom(aPlayer);
			return;
		}
	}
}

bool Room::ExecuteBattle(Player& aPlayer)
{
	int menuChoice = 0;
	while (true)
	{
		system("cls");

		DisplayRoomTitles(myRoomIndex + 1, aPlayer);
		std::cout << "You are in battle! If you type wrong you miss your attack!\n\n";
		SetColor(32);
		std::cout << aPlayer.GetPlayerName() << "(you) Has " << aPlayer.GetCurrentHealth() << "HP\n\n";
		for (int i = 0; i < myAmountOfEnemies; i++)
		{
			if (myEnemies[i].GetHealth() <= 0)
			{
				DisplayChoiceBox(i + 1, true);
				SetColor(31);
				std::cout << " Enemy " << i + 1 << " Has " << myEnemies[i].GetHealth() << "HP\n";
			}
			else
			{
				DisplayChoiceBox(i + 1, true);
				SetColor(32);
				std::cout << " Enemy " << i + 1 << " Has " << myEnemies[i].GetHealth() << "HP\n";
			}
		}
		ResetColor();

		if (aPlayer.GetCurrentHealth() <= 0)
		{
			return false;
		}

		bool enemyIsAlive = false;
		for (int i = 0; i < myAmountOfEnemies; i++)
		{
			if (myEnemies[i].GetHealth() > 0)
			{
				enemyIsAlive = true;
				break;
			}
		}
		if (!enemyIsAlive)
		{
			return true;
		}

		std::cout << "\nChoose what enemy to attack first: \n";
		std::cin >> menuChoice;
		CheckForInputFails(menuChoice, 1, myAmountOfEnemies);

		for (int i = 1; i <= myAmountOfEnemies; i++)
		{
			if (i == menuChoice)
			{
				bool isGoingToGiveLoot = RandomizeInt(0, 1);
				myEnemies[i - 1].TakeDamage(aPlayer.GetAttackValue(), aPlayer, isGoingToGiveLoot);
			}
		}

		int enemiesCombinedDamage = 0;
		for (Enemy& enemy : myEnemies)
		{
			if (enemy.GetHealth() > 0)
			{
				int damageTaken = enemy.GetDamage() - aPlayer.GetDefence();
				if (damageTaken > 0)
				{
					enemiesCombinedDamage += damageTaken;
				}
			}
		}

		if (enemiesCombinedDamage > 0)
		{
			aPlayer.TakeDamage(enemiesCombinedDamage);
		}

		if (!aPlayer.GetAliveState())
		{
			return false;
		}
	}
}