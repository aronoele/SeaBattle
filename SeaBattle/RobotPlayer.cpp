#include <iostream>

#include "RobotPlayer.h"

using std::cout;
using std::cin;

RobotPlayer::RobotPlayer(const string& name) : Player(name) {}

RobotPlayer::RobotPlayer() : Player("") {}

RobotPlayer::~RobotPlayer() {}

void RobotPlayer::fire() {
	int xPosition;
	int yPosition;
	do {
		cout << "Input x: ";
		cin >> xPosition;
		cout << "Input y: ";
		cin >> yPosition;
	} while (shut(xPosition, yPosition));
}