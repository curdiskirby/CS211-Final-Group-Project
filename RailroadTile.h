#pragma once
#include "Tile.h"
#include "Player.h"

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