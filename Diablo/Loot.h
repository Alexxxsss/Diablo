#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Functions.h"

class Player;

struct LootObjectData
{
	std::string lootName;

	int strengthToAdd = 1;
	int agilityToAdd = 1;
	int physicalToAdd = 1;
	int weight = 1;

	std::string lootDescription = "does nothing";
};


class LootObject
{
public:
	explicit LootObject(const LootObjectData& typeData) : myTypeData(typeData){}

	const std::string& GetName() const { return myTypeData.lootName; }
	const std::string& GetDescription() const { return myTypeData.lootDescription; }
	int GetStrength() const { return myTypeData.strengthToAdd; }
	int GetAgility() const { return myTypeData.agilityToAdd; }
	int GetPhysical() const { return myTypeData.physicalToAdd; }
	int GetWeight() const { return myTypeData.weight; }
private:
	const LootObjectData& myTypeData; // Peka/referera till datan i aItemFactory
};



enum class LootType
{
	StrengthStone,
	AgilityStone,
	PhysicalStone,
	Scrap
};



class ItemFactory
{
public:
	ItemFactory()
	{
		myPhysicalStoneData = {
			"PhysicalStone",
			0, // strength
			0, // agility
			1, // physical
			1, // weight
			"A You get more physical."

		};
		myAgilityStoneData = {
			"AgilityStone",
			0, // strength
			1, // agility
			0, // physical
			1, // weight
			"You get more agility."

		};
		myStrengthStoneData = {
			"StrengthStone",
			1, // strength
			0, // agility
			0, // physical
			1, // weight
			"You get more stregth."

		};
		myScrapData = {
			"Scrap",
			0, // strength
			0, // agility
			0, // physical
			1, // weight

		};
	}
	LootObject Create(LootType type) const
	{
		switch (type)
		{
		case LootType::StrengthStone:
			return LootObject(myStrengthStoneData);

		case LootType::AgilityStone:
			return LootObject(myAgilityStoneData);

		case LootType::PhysicalStone:
			return LootObject(myPhysicalStoneData);

		default:
			return LootObject(myScrapData);

		}
	}

	LootObject CreateRandomObject()
	{
		int randomObjectIndex = RandomizeInt(0, myAmountOfLoot - 1);
		switch (randomObjectIndex)
		{
			case 0:
			{
				return LootObject(myStrengthStoneData);
				break;
			}
			case 1:
			{
				return LootObject(myAgilityStoneData);
				break;
			}
			case 2:
			{
				return LootObject(myPhysicalStoneData);
				break;
			}
			case 3:
			{
				return LootObject(myScrapData);
				break;
			}
		}
		return LootObject(myScrapData);
	}

	int GetAmountOfLoot() const { return myAmountOfLoot; }


private:
	LootObjectData myPhysicalStoneData;
	LootObjectData myAgilityStoneData;
	LootObjectData myStrengthStoneData;
	LootObjectData myScrapData;

	int myAmountOfLoot = 4;
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

void GetRandomLootFromEnemyKilled(Player& aPlayer, ItemFactory &aItemFactory);
LootObject ReturnRandomLoot(ItemFactory& aItemFactory);
Spells ReturnRandomSpell(Player& aPlayer);
void DisplayActiveSpells(Player& aPlayer);

class Chest
{
public:
	void OpenChest(Player& aPlayer, ItemFactory &aItemFactory);
};
