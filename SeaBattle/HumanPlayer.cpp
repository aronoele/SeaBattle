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

void HumanPlayer::show() {
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
				cout << char(219);
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