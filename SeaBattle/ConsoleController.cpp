#include "ConsoleController.h"
#include "Game.h"

ConsoleController::ConsoleController(Game* game) : game_(game) {}

ConsoleController::~ConsoleController() {}

void ConsoleController::start() {
	while (!game_->isOver()) {
		/*game_->humanFire();
		if (game_->isOver())
			return;
		game_->robotFire();*/
		game_->changeState();
	}
}