#pragma once

class Enemy
{
public:
	int GetHealth() const { return myHealth; }
	int GetDamage() const { return myDamage; }
	bool GetIsAlive() const { return myIsAlive; }

	void SetAliveState(const bool aIsAlive) { myIsAlive = aIsAlive; }
	void SetHealth(const int aHealth) { myHealth = aHealth; }
	void SetDamage(const int aDamage) { myDamage = aDamage; }

	void TakeDamage(int aDamage)
	{
		myHealth -= aDamage;
		if (myHealth <= 0)
		{
			SetAliveState(false);
			myHealth = 0;
		}
	}

private:
	int myHealth = 30;
	int myDamage = 14;
	bool myIsAlive = true;
};