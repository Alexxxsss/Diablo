#include <string>
#include <iostream>
#include <vector>
#include "Loot.h"
#include "Main.h"

void Chest::OpenChest(Player& aPlayer, ItemFactory &aItemFactory)
{
	LootObject loot = aItemFactory.CreateRandomObject();
	std::cout << "Oh a chest found!";
	std::string question = "Do you want to open chest";

	if (AskYesOrNoQuestion(question))
	{
		question = "Oh you got " + static_cast<std::string>(loot.GetName()) + " from the chest, wanna pick that up?";

		if (aPlayer.GetWeightCapacity() < aPlayer.CalculateInventoryWeight() + loot.GetWeight())
		{
			std::cout << loot.GetName() << " is to heavy for you inventory";
		}
		else 
		{
			if (AskYesOrNoQuestion(question))
			{
				aPlayer.GetAllCurrentLoot().push_back(loot);
				aPlayer.RecalebrateStats();
			}
		}

		
	}
}




void GetRandomLootFromEnemyKilled(Player &aPlayer, ItemFactory &aItemFactory)
{
	LootObject loot = aItemFactory.CreateRandomObject();


	std::string question = "Congrats to your kill, wanna pick up the item he hold on to named: " + static_cast<std::string>(loot.GetName());
	
	if (aPlayer.GetWeightCapacity() < aPlayer.CalculateInventoryWeight() + loot.GetWeight())
	{
		std::cout << loot.GetName() << " is to heavy for you inventory";
	}
	else
	{
		if (AskYesOrNoQuestion(question))
		{
			aPlayer.GetAllCurrentLoot().push_back(loot);
		}
	}
	
	aPlayer.RecalebrateStats();
}


LootObject ReturnRandomLoot(ItemFactory &aItemFactory)
{
	LootObject loot = aItemFactory.CreateRandomObject();

	return loot;
}


Spells ReturnRandomSpell(Player& aPlayer)
{
	int size = static_cast<int>(aPlayer.GetAllSpellsPossibleToGet().size());
	Spells spell = aPlayer.GetAllSpellsPossibleToGet()[RandomizeInt(0, size - 1)];

	return spell;
}

void DisplayActiveSpells(Player& aPlayer)
{
	SetColor(35);

	for (Spells& spell : aPlayer.GetAllCurrentSpells())
	{
		std::cout << spell.spellName << " : " << spell.spellDescription << "\n";
	}

	ResetColor();
}