#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Loot.h"

class Player
{
public:

	// Getters
	int GetStrength() const { return myStrength; }
	int GetAgility() const { return myAgility; }
	int GetPhysical() const { return myPhysical; }
	int GetMaxHealth() const { return myMaxHealth; }
	int GetAttackValue() const { return myAttackValue; }
	int GetWeightCapacity() const { return myWeightCapacity; }
	int GetDefence() const { return myDefence; }
	int GetCurrentHealth() const { return myCurrentHealth; }
	bool GetAliveState() const { return myIsAlive; }
	std::string GetPlayerName() const { return myPlayerName; }
	bool GetHasBeenToEveryRoom() const { return myHasBeenToEveryRoom; }

	// Setters & Actions
	void SetPlayerAliveState(const bool aIsAlive) { myIsAlive = aIsAlive; }
	void SetHasBeenToEveryRoom(bool aHasBeen) { myHasBeenToEveryRoom = aHasBeen; }

	void TakeDamage(int aDamage)
	{
		myCurrentHealth -= aDamage;
		if (myCurrentHealth <= 0)
		{
			SetPlayerAliveState(false);
			myCurrentHealth = 0;
		}
	}

	void SetPlayerHealthForCheats(int aPlayerHealth)
	{
		myMaxHealth = aPlayerHealth;
		myCurrentHealth = aPlayerHealth;
	}

	void SetPlayerDamageForCheats(int aAttackValue)
	{
		myAttackValue = aAttackValue;
	}

	void SetPlayerName(std::string aPlayerName)
	{
		myPlayerName = aPlayerName;
	}

	/*
	std::vector<LootObject> &GetAllLootPossibleToGet()
	{
		//return myAllThePossibleLootToGet;
	}
	*/

	std::vector<LootObject>& GetAllCurrentLoot()
	{
		return myCurrentLoot;
	}

	std::vector<Spells>& GetAllSpellsPossibleToGet()
	{
		return myAllThePossibleSpellsToGet;
	}

	std::vector<Spells>& GetAllCurrentSpells()
	{
		return myCurrentSpells;
	}


	void RecalebrateSpellsAfterLeavingRoom()
	{
		for (Spells& spell : myCurrentSpells)
		{
			spell.roomDuration--;
			RecalebrateSpells();
		}

		RecalebrateStats();
	}

	void RecalebrateSpells()
	{
		mySpellStrength = 0;
		mySpellAgility = 0;
		mySpellPhysical = 0;
		int index = 0;

		for (Spells& spell : myCurrentSpells)
		{
			if (spell.roomDuration == 0)
			{
				myCurrentSpells.erase(myCurrentSpells.begin() + index);

				mySpellStrength -= spell.strngthToAdd;
				mySpellAgility -= spell.agilityToAdd;
				mySpellPhysical -= spell.physicalToAdd;
			}
			else
			{
				mySpellStrength += spell.strngthToAdd;
				mySpellAgility += spell.agilityToAdd;
				mySpellPhysical += spell.physicalToAdd;
			}
			index++;
		}
		RecalebrateStats();
	}


	void RecalebrateStats()
	{
		myStrength = myStartStrength;
		myAgility = myStartAgility;
		myPhysical = myStartPhysical;

		for (LootObject &loot : myCurrentLoot)
		{
			myStrength = myStrength + loot.GetStrength() + mySpellStrength;
			myAgility = myAgility + loot.GetAgility() + mySpellAgility;
			myPhysical = myPhysical + loot.GetPhysical() + mySpellPhysical;
		}


		myMaxHealth = (myPhysical * 4 + myStrength * 6 + myAgility * 3);
		myAttackValue = (myStrength * myAgility);
		myWeightCapacity = (myStrength + myAgility / 3);
		myDefence = (myPhysical + myAgility);
	}

	int CalculateInventoryWeight()
	{
		int weight = 0;

		for (LootObject loot : myCurrentLoot)
		{
			weight += loot.GetWeight();
		}


		return weight;
	}

private:
	int myStrength = 5;
	int myAgility = 5;
	int myPhysical = 5;

	int myStartStrength = myStrength;
	int myStartAgility = myAgility;
	int myStartPhysical = myPhysical;

	int mySpellStrength = 0;
	int mySpellAgility = 0;
	int mySpellPhysical = 0;

	int myMaxHealth = (myPhysical * 4 + myStrength * 6 + myAgility * 3);
	int myAttackValue = (myStrength * myAgility);
	int myWeightCapacity = (myStrength + myAgility / 3);
	int myDefence = (myPhysical + myAgility);

	int myCurrentHealth = myMaxHealth;
	bool myIsAlive = true;
	bool myHasBeenToEveryRoom = false;
	std::string myPlayerName;


	std::vector<LootObject> myCurrentLoot;

	std::vector<Spells> myAllThePossibleSpellsToGet = { Spells{"Strength Spell",1,0,0,2, "You get more stregth"},Spells{"Agility Spell",0,1,0,2, "You get more agility"},Spells{"Physical Spell",0,0,1,2, "You get more physical"} };
	std::vector<Spells> myCurrentSpells;
};

enum class MenuStates
{
	Play,
	Stats,
	Quit
};

void RunGameLoop(Player& aPlayer, ItemFactory& aItemFactory);
bool RunMenu(Player& aPlayer);
void DisplayStatsInMenu(Player& aPlayer);
MenuStates GetMenuChoiceState(int& aChoice);
void DisplayPregameOptions(Player& aPlayer);