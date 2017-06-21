#include "Game.h"

Game::Game()
{
	humanPlayer_.setName("Human");
	robotPlayer_.setName("Robot");
}

Game::~Game() {}

bool Game::isOver() {
	return false;
}

void Game::changeState() {

}

const HumanPlayer& Game::getHumanPlayer() const {
	return humanPlayer_;
}

const RobotPlayer& Game::getRobotPlayer() const {
	return robotPlayer_;
}

void Game::humanFire() {
	robotPlayer_.fire();
	//changeState();
	notifyUpdate();
}

void Game::robotFire() {
	humanPlayer_.fire();
	//changeState();
	notifyUpdate();
}