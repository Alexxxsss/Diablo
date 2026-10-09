#include <iostream>
#include <string>
#include "Main.h"

int main()
{
	Player player;
	ItemFactory itemFactory;
	RunGameLoop(player, itemFactory);
	return 0;
}
