#include "GameManager.h"
#include "PropertyTile.h"
#include "RailroadTile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager() : currentPlayerIndex(0), gameOver(false) {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // Randomized seed for the board
}

GameManager::~GameManager() {
	cleanUp();
}

void GameManager::setupGame() {
	std::string playerName;
	for (int i = 0; i < 2; ++i) {
		std::cout << "Enter name for Player " << (i + 1) << ": ";
		std::cin >> playerName;
		players.emplace_back(playerName);
	}

	setupBoard();
}

void GameManager::setupBoard() {
	board.push_back(new PropertyTile("Park Place", 350, 50));
	board.push_back(new PropertyTile("Boardwalk", 400, 60));
	board.push_back(new RailroadTile("Reading Railroad", 25));
	board.push_back(new PropertyTile("Marvin Gardens", 300, 40));
	board.push_back(new RailroadTile("Pennsylvania Railroad", 25));
	board.push_back(new PropertyTile("Ventnor Avenue", 320, 45));
	board.push_back(new RailroadTile("B&O Railroad", 25));
	board.push_back(new PropertyTile("Atlantic Avenue", 300, 40));
	board.push_back(new PropertyTile("Illinois Avenue", 280, 35));
	board.push_back(new RailroadTile("Short Line", 25));
	board.push_back(new PropertyTile("St. James Place", 180, 25));
	board.push_back(new PropertyTile("Connecticut Avenue", 120, 20));
}

void GameManager::gameLoop() {
	while (!gameOver) {
		Player& currentPlayer = players[currentPlayerIndex];
		takeTurn(currentPlayer);

		currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
	}
}

void GameManager::takeTurn(Player& player) {
	std::cout << "\n" << player.getName() << "'s turn.\n";
	std::cout << player.getName() << "'s current balance: $" << player.getMoney() << "\n";

	std::cout << "Press Enter to roll the dice...\n";
	std::cin.ignore();
	std::cin.get();

	int diceRoll = (std::rand() % 6) + 1;
	std::cout << player.getName() << " rolled a " << diceRoll << ".\n";
	player.move(diceRoll);

	Tile* currentTile = board[player.getPosition()];
	currentTile->landedOn(player);

	if (player.getMoney() <= 0) {
		std::cout << player.getName() << " is bankrupt! Game over.\n";
		gameOver = true;
	}
}

void GameManager::cleanUp() {
	for (Tile* tile : board) {
		delete tile;
	}
	board.clear();
}