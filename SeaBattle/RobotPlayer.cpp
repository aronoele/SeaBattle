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
		while (!(cin >> xPosition) || xPosition > 9) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Wrong input. Try again: ";
		}
		cout << "Input y: ";
		while (!(cin >> yPosition) || xPosition > 9) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Wrong input. Try again: ";
		}
	} while (shut(xPosition, yPosition));
}