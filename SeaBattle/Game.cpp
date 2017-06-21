#include <iostream>
#include "Game.h"

using std::cout;

Game::Game()
{
	humanPlayer.setName("Human");
	robotPlayer.setName("Robot");
}

Game::~Game() {}

bool Game::isOver() {
	return false;
}

void Game::show() {
	auto humanField = humanPlayer.getField();
	auto robotField = robotPlayer.getField();
	cout << "\t    " << humanPlayer.getName().c_str() 
		<< "\t\t    " << robotPlayer.getName().c_str() << ":\n";
	cout << "\t  0123456789\t\t  0123456789\n";
	cout << "\t #----------#\t\t #----------#\n";
	for (int y = 0; y < humanPlayer.getHeight(); y++) {
		cout << "\t" << y << "|";
		for (int x = 0; x < humanPlayer.getWidth(); x++) {
			switch (humanField.at(x + humanPlayer.getHeight() * y).getCellState()) {
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
		for (int x = 0; x < humanPlayer.getWidth(); x++) {
			switch (robotField.at(x + humanPlayer.getHeight() * y).getCellState()) {
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
	cout << "\t #----------#\t\t #----------#\n";
}

void Game::play() {
	show();
	while (!isOver()) {
		robotPlayer.fire();
		system("cls");
		show();
		if (isOver())
			return;
		humanPlayer.fire();
		system("cls");
		show();
	}	
}