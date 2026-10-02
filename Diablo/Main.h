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

	std::vector<LootObject> myAllThePossibleLootToGet = { LootObject{"Strength Stone",2,1,1},LootObject{"Agility Stone",1,2,1},LootObject{"Physical Stone",1,1,2} };
	std::vector<LootObject> myCurrentLoot;

private:
	int myStrength = 5;
	int myAgility = 5;
	int myPhysical = 5;
	int myMaxHealth = (myPhysical * 4 + myStrength * 6 + myAgility * 3);
	int myAttackValue = (myStrength * myAgility);
	int myWeightCapacity = (myStrength + myAgility / 3);
	int myDefence = (myPhysical + myAgility);

	int myCurrentHealth = myMaxHealth;
	bool myIsAlive = true;
	bool myHasBeenToEveryRoom = false;
	std::string myPlayerName;
};

enum class MenuStates
{
	Play,
	Stats,
	Quit
};

void WaitForEnterToContinue();
void PrintDiabloLogo();
void RunGameLoop(Player& aPlayer);
void ShowStats(Player& aPlayer);
void SetColor(int aTextColor);
void ResetColor();
int RandomizeInt(int aMinInclusive, int aMaxInclusive);
bool RunMenu(Player& aPlayer);
void DisplayStatsInMenu(Player& aPlayer);
void DisplayChoiceBox(int aChoice, bool aIsInt = false);
MenuStates GetMenuChoiceState(int& aChoice);
bool AskYesOrNoQuestion(std::string aQuestion, std::string aPositiveAlternative = "YES", std::string aNegativeAlternative = "NO");
void CheckForInputFails(int aInput, int aMinInput, int aMaxInput);
void DisplayRoomTitles(int aRoomIndex);
int AskMultipleChoiceQuestion(int aMinValue = 1, int aMaxValue = 3, std::vector<std::string> aAllChoices = {});
bool CheckIfYouBeenToAllRooms();
void DisplayPregameOptions(Player& aPlayer);