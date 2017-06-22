#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Cell.h"
#include "Ship.h"

using std::vector;
using std::string;

class Player {
public:
	Player(const string& namee);
	virtual ~Player();
	string getName() const;
	int getWidth() const;
	int getHeight() const;
	void setName(const string& name);
	bool randomizeField();
	bool isUnavailable(int xPosition, int yPosition, bool isHorizontal, int deckCount);	
	virtual bool isHit() = 0;
	int getAliveShipCount() const;
	const vector<Cell>& getField() const;
protected:
	string name_;
	int width_;
	int height_;
	int shipCount_;
	vector<Cell> field_;
	vector<Ship> ships_;
	int aliveShipCount_;
	bool isShot(int x, int y);
};

#endif // PLAYER_H
