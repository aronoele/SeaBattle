#ifndef SHIP_H
#define SHIP_H

#include <vector>

#include "Cell.h"

class Ship {
public:
	Ship(int size, const std::vector<Cell>& decks);
	~Ship();
	void reduceHealth();
	int getHealth() const;
	const std::vector<Cell>& getDecks() const;
	bool isShot(int x, int y);
private:
	int size_;
	std::vector<Cell> decks_;
	int health_;
};

#endif // SHIP_H