// MonopolyMain.cpp
// Curtis Teng & Benjamin Sanchez
// 4/14/2025

#include "GameManager.h"

// Main function to run the Monopoly game
int main() {
	GameManager game;
	try {
		game.setupGame();
		game.gameLoop();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 1;
}