#include <iostream>
#include <ctime>

#include "HumanPlayer.h"

using std::cout;
using std::cin;

HumanPlayer::HumanPlayer(const string& name) : Player(name) {}

HumanPlayer::HumanPlayer() : Player("") {}

HumanPlayer::~HumanPlayer() {}

void HumanPlayer::fire() {
	srand(time(0));
	int xPosition;
	int yPosition;
	do {
		xPosition = rand() % width_;
		yPosition = rand() % height_;
	} while (shut(xPosition, yPosition));
}