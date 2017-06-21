#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
	HumanPlayer(const string& name);
	HumanPlayer();
	~HumanPlayer();
	void fire() override;
};

#endif // HUMANPLAYER_H