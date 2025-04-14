#pragma once
#include <iostream>
#include <string>

class Player;

class Tile {
public:
	Tile(const std::string& name) :name(name) {}
	virtual ~Tile() {}
	
	virtual void landedOn(Player& player) = 0;
	virtual std::string getName() const { return name; }
protected:
	std::string name;
};