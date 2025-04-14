#pragma once
#include <vector>
#include "Player.h"
#include "Tile.h"

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
};