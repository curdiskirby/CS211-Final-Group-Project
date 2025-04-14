#include "Player.h"
#include <iostream>

void Player::move(int spaces) {
	position = (position + spaces) % 12; // Wraps around the board size of 12 total tiles
	std::cout << name << " moves " << spaces << " spaces to position " << position << ".\n";
}

int Player::getPosition() const { return position; }
void Player::setPosition(int pos) { position = pos; }

std::string Player::getName() const { return name; }
int Player::getMoney() const { return money; }

void Player::addMoney(int amount) {
	money += amount;
	std::cout << name << " receives $" << amount << ". New balance: $" << money << ".\n";
}

void Player::subtractMoney(int amount) {
	if (amount > money) {
		std::cout << name << " does not have enough money to pay $" << amount << ".\n";
		money = 0; // Set money to zero if bankrupt
	}
	else {
		money -= amount;
		std::cout << name << " pays $" << amount << ". New balance: $" << money << ".\n";
	}
}