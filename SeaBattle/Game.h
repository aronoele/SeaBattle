#pragma once

#include "HumanPlayer.h"
#include "RobotPlayer.h"

class Game {
public:
	Game();
	~Game();
	bool isOver();
	void play();
private:
	HumanPlayer humanPlayer;
	RobotPlayer robotPlayer;
};
