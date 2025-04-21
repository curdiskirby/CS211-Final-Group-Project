// GameManager.cpp
// Curtis Teng & Benjamin Sanchez
// 4/14/2025 

#include "GameManager.h"
#include "PropertyTile.h"
#include "RailroadTile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


// GameManager class manages the game state, including players and the game board.
GameManager::GameManager() : currentPlayerIndex(0), gameOver(false) {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // Randomized seed for the board
}

// Destructor to clean up dynamically allocated tiles
GameManager::~GameManager() {
	cleanUp();
}

// Function to set up the game, including player names and board tiles
void GameManager::setupGame() {
	std::string playerName;
	for (int i = 0; i < 2; ++i) {
		std::cout << "Enter name for Player " << (i + 1) << ": ";
		std::cin >> playerName;
		players.emplace_back(playerName);
	}

	setupBoard();
}

// Function to set up the game board with tiles
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

// Function to run the main game loop
void GameManager::gameLoop() {
	while (!gameOver) {
		Player& currentPlayer = players[currentPlayerIndex];
		std::cout << "\n-- " << currentPlayer.getName() << "'s Turn --\n";
		std::cout << "1. Roll the dice\n";
		std::cout << "2. Save game\n";
		std::cout << "3. Load game\n";
		std::cout << "Choose an option: ";

		int choice;
		std::cin >> choice;

		try {
			switch (choice) {
			case 1:
				takeTurn(currentPlayer);
				break;
			case 2: {
				saveGame("savefile.txt");
				break;
			}
			case 3: {
				loadGame("savefile.txt");
				break;
			}
			default:
				std::cout << "Invalid choice. Try again.\n";
				continue;
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		// Move to the next player
		currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
	}
}

// Function to handle a player's turn
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

// Function to clean up dynamically allocated tiles
void GameManager::cleanUp() {
	for (Tile* tile : board) {
		delete tile;
	}
	board.clear();
}

// Function to save the game state to a file
void GameManager::saveGame(const std::string& filename) {
	std::ofstream outFile(filename);
	if (!outFile) {
		throw std::runtime_error("Could not open file for saving.");
	}

	for (const auto& player : players) {
		outFile << player.getName() << " " << player.getMoney() << " " << player.getPosition() << "\n";
	}

	outFile.close();
	std::cout << "Game saved to " << filename << ".\n";
}

// Function to load the game state from a file
void GameManager::loadGame(const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile) {
		throw std::runtime_error("Could not open file for loading.");
	}

	// Clear existing players before loading
	players.clear(); 
	std::string name;
	int money, position;

	// Read player data from the file
	while (inFile >> name >> money >> position) {
		Player player(name);
		player.setMoney(money);
		player.setPosition(position);
		players.push_back(player);
	}

	// Load the board state if necessary
	inFile.close();
	std::cout << "Game loaded from " << filename << ".\n";
}