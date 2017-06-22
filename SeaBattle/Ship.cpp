#include "Ship.h"
#include "Cell.h"

Ship::Ship(int size, const std::vector<Cell>& decks) : size_(size), health_(size_), decks_(decks) {}

Ship::~Ship() {}

void Ship::reduceHealth() {
	if (health_ != 0)
		health_--;
}

int Ship::getHealth() const {
	return health_;
}

const std::vector<Cell>& Ship::getDecks() const {
	return decks_;
}

bool Ship::isShot(int x, int y) {
	for (int i = 0; i < size_; i++) {
		if (decks_.at(i).getXPosition() == x && decks_.at(i).getYPosition() == y && decks_.at(i).isShot()) {
			reduceHealth();
			return true;
		}
	}
	return false;
}