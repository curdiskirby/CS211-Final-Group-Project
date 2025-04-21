// RailroadTile.cpp
// Curtis Teng
// 4/14/2025

#include "RailroadTile.h"
#include <iostream>


// Function to handle when a player lands on a railroad tile
void RailroadTile::landedOn(Player& player) {
	std::cout << player.getName() << " landed on " << name << ".\n";
	std::cout << "Paying the railroad fare of $" << amount << ".\n";
	player.subtractMoney(amount);
}