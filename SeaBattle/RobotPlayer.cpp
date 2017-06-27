#include <iostream>

#include "RobotPlayer.h"

using std::cout;
using std::cin;

RobotPlayer::RobotPlayer(const string& name) : Player(name) {}

RobotPlayer::RobotPlayer() : Player("") {}

RobotPlayer::~RobotPlayer() {}

bool RobotPlayer::isHit() {
	int xPosition;
	int yPosition;
	cout << "Input x: ";
	while (!(cin >> xPosition) || xPosition > 9) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Wrong input. Try again: ";
	}
	cout << "Input y: ";
	while (!(cin >> yPosition) || yPosition > 9) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Wrong input. Try again: ";
	}
	return isShot(xPosition, yPosition);
}