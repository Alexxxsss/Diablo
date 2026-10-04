#include <string>
#include <iostream>
#include <vector>
#include "Loot.h"
#include "Main.h"

void Chest::OpenChest(Player& aPlayer)
{
	std::cout << "Oh a chest found!";
	std::string question = "Do you want to open chest";

	if (AskYesOrNoQuestion(question))
	{
		int size = static_cast<int>(aPlayer.myAllThePossibleLootToGet.size());
		LootObject loot = aPlayer.myAllThePossibleLootToGet[RandomizeInt(0, size - 1)];
		question = "Oh you got " + static_cast<std::string>(loot.lootName) + " from the chest, wanna pick that up?";

		if (aPlayer.GetWeightCapacity() < aPlayer.CalculateInventoryWeight() + loot.weight)
		{
			std::cout << loot.lootName << " is to heavy for you inventory";
		}
		else 
		{
			if (AskYesOrNoQuestion(question))
			{
				aPlayer.myCurrentLoot.push_back(loot);
				aPlayer.RecalebrateStats();
			}
		}

		
	}
}




void GetRandomLootFromEnemyKilled(Player &aPlayer)
{
	int size = static_cast<int>(aPlayer.myAllThePossibleLootToGet.size());
	LootObject loot = aPlayer.myAllThePossibleLootToGet[RandomizeInt(0, size-1)];

	std::string question = "Congrats to your kill, wanna pick up the item he hold on to named: " + static_cast<std::string>(loot.lootName);
	
	if (aPlayer.GetWeightCapacity() < aPlayer.CalculateInventoryWeight() + loot.weight)
	{
		std::cout << loot.lootName << " is to heavy for you inventory";
	}
	else
	{
		if (AskYesOrNoQuestion(question))
		{
			aPlayer.myCurrentLoot.push_back(loot);
		}
	}
	
	aPlayer.RecalebrateStats();
}


LootObject ReturnRandomLoot(Player& aPlayer)
{
	int size = static_cast<int>(aPlayer.myAllThePossibleLootToGet.size());
	LootObject loot = aPlayer.myAllThePossibleLootToGet[RandomizeInt(0, size - 1)];

	return loot;
}


Spells ReturnRandomSpell(Player& aPlayer)
{
	int size = static_cast<int>(aPlayer.myAllThePossibleSpellsToGet.size());
	Spells spell = aPlayer.myAllThePossibleSpellsToGet[RandomizeInt(0, size - 1)];

	return spell;
}

void DisplayActiveSpells(Player& aPlayer)
{
	SetColor(35);

	for (Spells& spell : aPlayer.myCurrentSpells)
	{
		std::cout << spell.spellName << " : " << spell.spellDescription << "\n";
	}

	ResetColor();
}