#include "ConsoleController.h"
#include "Game.h"

ConsoleController::ConsoleController(Game* game) : game_(game) {}

ConsoleController::~ConsoleController() {}

void ConsoleController::start() {
	while (!game_->isOver()) {
		game_->humanFire();
		game_->robotFire();
	}
}