#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H

#include "Player.h"

class RobotPlayer : public Player {
public:
	RobotPlayer(const string& name);
	RobotPlayer();
	~RobotPlayer();
	bool isHit() override;
};

#endif // ROBOTPLAYER_H
