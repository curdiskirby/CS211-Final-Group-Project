// Tile.h
// Curtis Teng
// 4/14/2025

#pragma once
#include <iostream>
#include <string>

class Player;


// Base class for all tiles on the board
class Tile {
public:
	Tile(const std::string& name) :name(name) {}
	virtual ~Tile() {}
	
	virtual void landedOn(Player& player) = 0;
	virtual std::string getName() const { return name; }
protected:
	std::string name;
};