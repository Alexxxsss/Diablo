#pragma once
#include <string>
#include <iostream>
#include <vector>

class Player;

struct LootObject
{
	std::string lootName;

	int strngthToAdd = 1;
	int agilityToAdd = 1;
	int physicalToAdd = 1;
	int weight = 1;

	std::string lootDescription = "does nothing";
};

struct Spells
{
	std::string spellName;

	int strngthToAdd = 1;
	int agilityToAdd = 1;
	int physicalToAdd = 1;
	int roomDuration = 2;

	std::string spellDescription = "does nothing";
};

void GetRandomLootFromEnemyKilled(Player& aPlayer);
LootObject ReturnRandomLoot(Player& aPlayer);
Spells ReturnRandomSpell(Player& aPlayer);
void DisplayActiveSpells(Player& aPlayer);

class Chest
{
public:
	void OpenChest(Player& aPlayer);
};
