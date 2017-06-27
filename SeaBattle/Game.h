#ifndef GAME_H
#define GAME_H

#include "IModel.h"
#include "Observable.h"
#include "HumanPlayer.h"
#include "RobotPlayer.h"

class Game : public IModel, public Observable {
public:
	Game();
	~Game();
	bool isOver();
	void changeState() override;
	const HumanPlayer& getHumanPlayer() const;
	const RobotPlayer& getRobotPlayer() const;
	//void humanFire();
	//void robotFire();
private:
	HumanPlayer humanPlayer_;
	RobotPlayer robotPlayer_;
};

#endif // GAME_H
