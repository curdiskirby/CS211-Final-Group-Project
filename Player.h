// Player.h
// Curtis Teng & Benjamin Sanchez
// 4/14/2025

#pragma once
#include <string>

/// Player class represents a player in the Monopoly game
class Player {
private:
	std::string name;
	int money;
	int position;
public:
	Player(const std::string& name, int money = 1500)
		: name(name), money(money), position(0) {
	}

	void move(int spaces);
	int getPosition() const;
	void setPosition(int pos);

	std::string getName() const;
	int getMoney() const;
	void addMoney(int amount);
	void subtractMoney(int amount);
	void adjustMoney(int amount);
	void setMoney(int money);
};