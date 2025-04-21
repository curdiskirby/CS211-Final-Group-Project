// Player.cpp
// Curtis Teng & Benjamin Sanchez
// 4/14/2025

#include "Player.h"
#include <iostream>


// Player class constructor initializes the player's name, money, and position
void Player::move(int spaces) {
	position = (position + spaces) % 12; // Wraps around the board size of 12 total tiles
	std::cout << name << " moves " << spaces << " spaces to position " << position << ".\n";
}

// Function to move the player a certain number of spaces on the board
int Player::getPosition() const { return position; }
void Player::setPosition(int pos) { position = pos; }


// Function to get the player's name and money
std::string Player::getName() const { return name; }
int Player::getMoney() const { return money; }


// Function to add money to the player's balance
void Player::addMoney(int amount) {
	money += amount;
	std::cout << name << " receives $" << amount << ". New balance: $" << money << ".\n";
}

// Function to subtract money from the player's balance
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

// Function to adjust the player's money by a certain amount
void Player::adjustMoney(int amount) {
	if (money + amount < 0) {
		std::cout << name << " cannot afford to pay! Current balance: $ " << money << ", needed: $" << -amount << "\n";
		money = 0; // Set money to zero if bankrupt
		return;
	}
	money += amount;
}

// Function to set the player's money to a specific amount
void Player::setMoney(int money) {
	this->money = money;
	std::cout << name << "'s money set to $" << money << ".\n";
}