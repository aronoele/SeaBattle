#include "Game.h"

Game::Game()
{
	humanPlayer.setName("Human");
	robotPlayer.setName("Robot");
}

Game::~Game() {}

bool Game::isOver() {
	return false;
}

void Game::play() {
	humanPlayer.show();
	robotPlayer.show();
	while (!isOver()) {
		robotPlayer.fire();
		system("cls");
		humanPlayer.show();	
		robotPlayer.show();
		if (isOver())
			return;
		humanPlayer.fire();
		system("cls");
		humanPlayer.show();
		robotPlayer.show();
	}	
}