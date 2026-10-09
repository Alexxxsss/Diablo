#pragma once
#include <iostream>
#include <vector>
#include <string>


class Player;

void ShowStats(Player& aPlayer);
void PrintDiabloLogo();
void DisplayRoomTitles(int aRoomIndex, Player& aPlayer);
void WaitForEnterToContinue();
bool CheckIfYouBeenToAllRooms();
void SetColor(int aTextColor);
void ResetColor();
void DisplayChoiceBox(int aChoice, bool aIsInt = false);
bool AskYesOrNoQuestion(std::string aQuestion, std::string aPositiveAlternative = "YES", std::string aNegativeAlternative = "NO");
void CheckForInputFails(int aInput, int aMinInput, int aMaxInput);
int AskMultipleChoiceQuestion(int aMinValue = 1, int aMaxValue = 3, std::vector<std::string> aAllChoices = {});
int RandomizeInt(int aMinInclusive, int aMaxInclusive);
