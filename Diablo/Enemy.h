#pragma once

class Enemy
{
public:
	const int GetHealth() { return health; }							//Returning current Health
	const int GetDamage() { return damage; }							//Returning Damage
	void ChangeEnemyAliveState(const bool aState) { alive = aState; }	//Changes the Alive State

	void TakeDamage(int aDamage)
	{
		health -= aDamage;					//Deals damage to current Enemy
		if (health <= 0)					//Checks if Enemy is Dead
		{
			ChangeEnemyAliveState(false);	//Set the enemy Dealth State to true
			health = 0;
		}
	}

private:
	int health = 30;
	int damage = 14;
	bool alive = true;
};
