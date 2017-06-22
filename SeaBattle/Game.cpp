#include "Game.h"

Game::Game()
{
	humanPlayer_.setName("Human");
	robotPlayer_.setName("Robot");
}

Game::~Game() {}

bool Game::isOver() {
	return (humanPlayer_.getAliveShipCount() == 0 || robotPlayer_.getAliveShipCount() == 0);
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
	while (robotPlayer_.isHit()) {
		//changeState();
		notifyUpdate();
	}
	notifyUpdate();
}

void Game::robotFire() {
	while (humanPlayer_.isHit()) {
		//changeState();
		notifyUpdate();
	}
	notifyUpdate();
}