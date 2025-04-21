// PropertyTile.h
// Curtis Teng
// 4/14/2025

#pragma once
#include "Tile.h"
#include "Player.h"


/*
  PropertyTile class represents a property tile on the Monopoly board.
  It inherits from the Tile class and implements the landedOn method.
  The player can buy the property or pay rent if it is owned by another player.
*/
class PropertyTile : public Tile {
private:
	int price;
	int rent;
	Player* owner;
public:
	PropertyTile(const std::string& name, int price, int rent)
		: Tile(name), price(price), rent(rent), owner(nullptr) {
	}

	void landedOn(Player& player) override;

	bool isOwned() const { return owner != nullptr; }
	Player* getOwner() const { return owner; }
	void setOwner(Player* newOwner) { owner = newOwner; }

	int getPrice() const { return price; }
	int getRent() const { return rent; }
};