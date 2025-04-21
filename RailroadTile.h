// RailroadTile.h
// Curtis Teng
// 4/14/2025

#pragma once
#include "Tile.h"
#include "Player.h"


/*
  RailroadTile class represents a railroad tile on the Monopoly board.
  It inherits from the Tile class and implements the landedOn method.
 */
class RailroadTile : public Tile {
private:
	int amount;
public:
	RailroadTile(const std::string& name, int amount)
		: Tile(name), amount(amount) {
	}

	void landedOn(Player& player) override;

	int getAmount() const { return amount; }
};