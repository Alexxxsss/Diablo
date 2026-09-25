#pragma once
#include <string>
#include <iostream>
#include <vector>


class Player
{
public:
	const int GetStrength() { return strength; }				//	strength
	const int GetAgility() { return agility; }					//	agility
	const int GetPhysical() { return physical; }				//	physical
	const int GetMaxHealth() { return maxHealth; }				//	maxHealth
	const int GetAttackValue() { return attackValue; }			//	attackValue
	const int GetWeightCapacity() { return weightCapacity; }	//	weightCapacity
	const int GetDefence() { return defence; }					//	defence

private:
	int strength = 5;
	int agility = 5;
	int physical = 5;
	int maxHealth = (physical * 4 + strength * 6 + agility * 3);
	int attackValue = (strength * agility);
	int weightCapacity = (strength + agility / 3);
	int defence = (physical + agility);
};

class Door
{

public:
	Door(Room room);
	Room room;
};

class Room
{
public:
	Room();
	void EnterRoom(std::vector<Room> allRooms);
	std::vector<Door> doors;
};


enum class MenuStates //Val I Menyn
{
	Play,
	Stats,
	Quit
};

void EnterToContinue();
void Diablo();
void GameLoop(Player& aPlayer);
void ShowStats(Player& aPlayer);

/// <summary>
///	31: Röd -=- 32: Grön -=- 33: Gul -=- 34: Blå -=- 35: Lila -=- 37: Vit
/// </summary>
void SetColor(int textColor);
void ResetColor();
int RandomizeInt(int aMinExclusive, int aMaxNonExclusive);
bool Menu(Player& aPlayer);
void DisplayStatsInMenu(Player& aPlayer);
void MenuChoiseBoxes(char aChoise);
MenuStates GetMenuChoiseState(int& aChoise);
bool YesOrNoQuestion(std::string aQuestion, std::string aPositiveAlternative = "YES", std::string aNegativeAlternative = "NO");
void CheckForInputFails(int input, int aMinInput, int aMaxInput);