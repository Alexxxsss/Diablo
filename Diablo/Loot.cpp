#include <string>
#include <iostream>
#include <vector>
#include "Loot.h"
#include "Main.h"

void OpenChest(Player& aPlayer)
{
	int size = static_cast<int>(aPlayer.myAllThePossibleLootToGet.size());
	LootObject loot = aPlayer.myAllThePossibleLootToGet[RandomizeInt(0, size - 1)];

	std::string question = "Wanna pick up the item from the mythical chest, the item is named: " + static_cast<std::string>(loot.lootName);
	if (AskYesOrNoQuestion(question))
	{
		aPlayer.myCurrentLoot.push_back(loot);
	}
}

void GetRandomLootFromEnemyKilled(Player &aPlayer)
{
	int size = static_cast<int>(aPlayer.myAllThePossibleLootToGet.size());
	LootObject loot = aPlayer.myAllThePossibleLootToGet[RandomizeInt(0, size-1)];

	std::string question = "Congrats to your kill, wanna pick up the item he hold on to named: " + static_cast<std::string>(loot.lootName);
	if (AskYesOrNoQuestion(question))
	{
		aPlayer.myCurrentLoot.push_back(loot);
	}
}