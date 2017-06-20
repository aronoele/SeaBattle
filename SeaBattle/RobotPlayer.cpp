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

void RobotPlayer::show() {
	//cout << "\t    " << getName().c_str() << ":\n";
	cout << "\t  0123456789\n";
	cout << "\t #----------#\n";
	for (int y = 0; y < height_; y++) {
		cout << "\t" << y << "|";
		for (int x = 0; x < width_; x++) {
			switch (field_.at(x + height_ * y).getCellState()) {
			case EMPTY:
				cout << " ";
				break;
			case CLEAN:
				cout << " ";
				break;
			case MISSED:
				cout << char(249);
				break;
			case SHOT:
				cout << char(177);
				break;
			}
		}
		cout << "|\n";
	}
	cout << "\t #----------#\n";
}