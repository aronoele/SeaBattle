#ifndef GAME_H
#define GAME_H

#include "HumanPlayer.h"
#include "RobotPlayer.h"

class Game {
public:
	Game();
	~Game();
	bool isOver();
	void show();
	void play();
private:
	HumanPlayer humanPlayer;
	RobotPlayer robotPlayer;
};

#endif // GAME_H
