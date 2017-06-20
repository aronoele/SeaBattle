#include "Ship.h"

Ship::Ship(int size, std::vector<Cell> decks)
{
	size_ = size;
	health_ = size_;
	decks_ = decks;
}

void Ship::wound() {
	if (health_ != 0)
		health_--;
}

int Ship::getHealth() {
	return health_;
}

Ship::~Ship() {}