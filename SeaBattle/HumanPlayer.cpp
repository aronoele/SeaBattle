#include <iostream>
#include <ctime>

#include "HumanPlayer.h"

using std::cout;
using std::cin;

HumanPlayer::HumanPlayer(const string& name) : Player(name) {}

HumanPlayer::HumanPlayer() : Player("") {}

HumanPlayer::~HumanPlayer() {}

bool HumanPlayer::isHit() {
	//srand(time(0));
	int xPosition = rand() % width_;
	int yPosition = rand() % height_;
	while (field_.at(xPosition + height_ * yPosition).getCellState() == CellState::MISSED
		|| field_.at(xPosition + height_ * yPosition).getCellState() == CellState::SHOT) {
		xPosition = rand() % width_;
		yPosition = rand() % height_;
	}
	return isShot(xPosition, yPosition);
}