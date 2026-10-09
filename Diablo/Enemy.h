#pragma once

class Player;
class ItemFactory;

void GetRandomLootFromEnemyKilled(Player& aPlayer, ItemFactory& aItemFactory);


class Enemy
{
public:
	int GetHealth() const { return myHealth; }
	int GetDamage() const { return myDamage; }
	bool GetIsAlive() const { return myIsAlive; }

	void SetAliveState(const bool aIsAlive) { myIsAlive = aIsAlive; }
	void SetHealth(const int aHealth) { myHealth = aHealth; }
	void SetDamage(const int aDamage) { myDamage = aDamage; }

	void TakeDamage(int aDamage, Player& aPlayer, ItemFactory& aItemFactory, bool giveLoot = false)
	{
		myHealth -= aDamage;
		if (myHealth <= 0)
		{

			if (myIsAlive == true && giveLoot)
			{
				GetRandomLootFromEnemyKilled(aPlayer, aItemFactory);
			}
			SetAliveState(false);
			myHealth = 0;
		}
	}

private:
	int myHealth = 30;
	int myDamage = 14;
	bool myIsAlive = true;
};