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

	std::string lootDescription = "does nothing";
};
void GetRandomLootFromEnemyKilled(Player& aPlayer);
LootObject ReturnRandomLoot(Player& aPlayer);
class Chest
{
public:
	void OpenChest(Player& aPlayer);
};
