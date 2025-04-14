#include "RailroadTile.h"
#include <iostream>

void RailroadTile::landedOn(Player& player) {
	std::cout << player.getName() << " landed on " << name << ".\n";
	std::cout << "Paying the railroad fare of $" << amount << ".\n";
	player.subtractMoney(amount);
}