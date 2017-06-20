#pragma once

#include "Player.h"

class RobotPlayer : public Player {
public:
	RobotPlayer(const string& name);
	RobotPlayer();
	~RobotPlayer();
	void fire() override;
	void show() override;
};
