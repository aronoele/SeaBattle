#ifndef SHIP_H
#define SHIP_H

#include <vector>

#include "Cell.h"

class Ship {
public:
	Ship(int size, std::vector<Cell> deck);
	~Ship();
	void wound();
	int getHealth();
private:
	int size_;
	std::vector<Cell> decks_;
	int health_;
};

#endif // SHIP_H