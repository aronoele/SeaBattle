#include <iostream>
#include <ctime>

#include "ConsoleView.h"

using std::cout;

ConsoleView::ConsoleView(Game* game) : game_(game) {
	game_->addObserver(this);
	start = time(0);
}

ConsoleView::~ConsoleView() {}

void ConsoleView::show() {
	update();
}

void ConsoleView::update() {
	system("cls");
	cout << "\n";
	cout << "\t    " << game_->getHumanPlayer().getName().c_str() << ":"
		<< "\t\t    " << game_->getRobotPlayer().getName().c_str() << ":";
	//int minutes = clock() / CLOCKS_PER_SEC / 60;
	//int seconds = clock() / CLOCKS_PER_SEC - minutes * 60;
	struct tm passTime;
	time_t pass = time(0) - start;
	localtime_s(&passTime, &pass);
	/*cout << "\t\tTime: " << minutes << ":" << seconds << "\n";*/
	cout << "\t\tTime: " << passTime.tm_min << ":" << passTime.tm_sec << "\n";
	cout << "\t  0123456789\t\t  0123456789\n";
	cout << "\t #----------#\t\t #----------#\n";
	for (int y = 0; y < game_->getHumanPlayer().getHeight(); y++) {
		cout << "\t" << y << "|";
		for (int x = 0; x < game_->getHumanPlayer().getWidth(); x++) {
			cout << char(game_->getHumanPlayer().getField().at(x + game_->getHumanPlayer().getHeight() * y).getCellState());
		}
		cout << "|\t\t" << y << "|";
		if (game_->isOver()) {
			for (int x = 0; x < game_->getRobotPlayer().getWidth(); x++) {
				cout << char(game_->getRobotPlayer().getField().at(x + game_->getRobotPlayer().getHeight() * y).getCellState());
			}
		}
		else {
			for (int x = 0; x < game_->getRobotPlayer().getWidth(); x++) {
				CellState state = game_->getRobotPlayer().getField().at(x + game_->getHumanPlayer().getHeight() * y).getCellState();
				if (state == CellState::CLEAN) {
					cout << char(CellState::EMPTY);
				}
				else {
					cout << char(state);
				}
			}
		}
		cout << "|\n";
	}
	cout << "\t #----------#\t\t #----------#\n";
	cout << "     Remaining ships: " << game_->getHumanPlayer().getAliveShipCount()
		<< "     Remaining ships: " << game_->getRobotPlayer().getAliveShipCount() << "\n\n";
	if (game_->isOver()) {
		cout << "\n\t\tGame i over.\n";
	}
}