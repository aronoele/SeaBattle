#include <iostream>

#include "ConsoleView.h"

using std::cout;

ConsoleView::ConsoleView(Game* game) : game_(game) {
	game_->addObserver(this);
}

ConsoleView::~ConsoleView() {}

void ConsoleView::show() {
	update();
}

void ConsoleView::update() {
	system("cls");
	cout << "\n";
	cout << "\t    " << game_->getHumanPlayer().getName().c_str()
		<< "\t\t    " << game_->getRobotPlayer().getName().c_str() << ":\n";
	cout << "\t  0123456789\t\t  0123456789\n";
	cout << "\t #----------#\t\t #----------#\n";
	for (int y = 0; y < game_->getHumanPlayer().getHeight(); y++) {
		cout << "\t" << y << "|";
		for (int x = 0; x < game_->getHumanPlayer().getWidth(); x++) {
			switch (game_->getHumanPlayer().getField().at(x + game_->getHumanPlayer().getHeight() * y).getCellState()) {
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
		cout << "|\t\t" << y << "|";
		for (int x = 0; x < game_->getRobotPlayer().getWidth(); x++) {
			switch (game_->getRobotPlayer().getField().at(x + game_->getHumanPlayer().getHeight() * y).getCellState()) {
			case EMPTY:
				cout << " ";
				break;
			case CLEAN:
				if (game_->isOver()) {
					cout << char(219);
				}
				else {
					cout << " ";
				}
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
	cout << "\t #----------#\t\t #----------#\n";
	cout << "     Remaining ships: " << game_->getHumanPlayer().getAliveShipCount()
		<< "     Remaining ships: " << game_->getRobotPlayer().getAliveShipCount() << "\n\n";
}