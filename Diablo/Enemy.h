#pragma once

class Enemy
{
	const int GetHealth() { return health; }							//Returning current Health
	bool ChangeEnemyAliveState(const bool aState) { alive = aState; }	//Changes the Alive State

	void TakeDamage(int aDamage)
	{
		health -= aDamage;					//Deals damage to current Enemy
		if (health <= 0)					//Checks if Enemy is Dead
		{
			ChangeEnemyAliveState(false);	//Set the enemy Dealth State to true
		}
	}

private:
	int health = 30;
	bool alive = true;
};