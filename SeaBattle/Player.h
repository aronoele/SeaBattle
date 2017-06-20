#pragma once

#include <vector>

#include "Cell.h"
#include "Ship.h"

using std::vector;
using std::string;

class Player {
public:
	Player(const string& namee);
	virtual ~Player();
	string getName();
	void setName(const string& name);
	bool randomizeField();
	bool isUnavailable(int xPosition, int yPosition, bool isHorizontal, int deckCount);	
	virtual void fire() = 0;
	int getAliveShipCount();
	vector<Cell> getField();
	virtual void show() = 0;
protected:
	string name_;
	const int width_ = 10;
	const int height_ = 10;
	const int shipCount_ = 10;
	vector<Cell> field_;
	vector<Ship> ships_;
	int aliveShipCount_;
	bool shut(int x, int y);
};
