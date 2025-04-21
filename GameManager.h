// GameManager.h
// Curtis Teng & Benjamin Sanchez
// 4/14/2025

#pragma once
#include <vector>
#include "Player.h"
#include "Tile.h"


/// GameManager class manages the game state, including players and the game board.
class GameManager {
private:
	std::vector<Player> players;
	std::vector<Tile*> board;
	int currentPlayerIndex;
	bool gameOver;
public:
	GameManager();
	~GameManager();

	void setupGame();
	void setupBoard();
	void gameLoop();
	void takeTurn(Player& player);
	void cleanUp();

	void saveGame(const std::string& filename);
	void loadGame(const std::string& filename);
};