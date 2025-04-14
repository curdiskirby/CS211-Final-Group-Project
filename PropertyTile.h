#pragma once
#include "Tile.h"
#include "Player.h"

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