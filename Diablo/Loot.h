#pragma once
#include <string>
#include <iostream>
#include <vector>

class Player;

struct LootObject
{
	std::string lootName;

	int strngthMultiplyer = 1;
	int agilityMultiplyer = 1;
	int physicalMultiplyer = 1;
};

void GetRandomLootFromEnemyKilled(Player& aPlayer);
void OpenChest(Player& aPlayer);
