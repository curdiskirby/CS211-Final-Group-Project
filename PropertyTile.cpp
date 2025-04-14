#include "PropertyTile.h"
#include <iostream>

void PropertyTile::landedOn(Player& player) {
	std::cout << player.getName() << " landed on " << name << ".\n";

	if (!owner) {
		std::cout << "This property is available for purchase at $" << price << ".\n";
		std::cout << "Do you want to buy it? (y/n): ";
		char choice;
		std::cin >> choice;

		if (choice == 'y' || choice == 'Y') {
			if (player.getMoney() >= price) {
				player.subtractMoney(price);
				owner = &player;
				std::cout << player.getName() << " bought " << name << ".\n";
			}
			else {
				std::cout << player.getName() << " does not have enough money to buy " << name << ".\n";
			}
		}
	}
	else if (owner != &player) {
		std::cout << player.getName() << " pays $" << rent << " rent to " << owner->getName() << ".\n";
		if (player.getMoney() >= rent) {
			player.subtractMoney(rent);
			owner->addMoney(rent);
		}
		else {
			std::cout << player.getName() << " does not have enough money to pay rent.\n";
			player.subtractMoney(player.getMoney()); // Set money to zero if bankrupt
		}
	}
	else {
		std::cout << player.getName() << " owns this property.\n";
	}
};