#include<iostream>
#include <ctime>

#include "Player.h"

using std::cout;

Player::Player(const string& name)
{
	name_ = name;
	for (int y = 0; y < height_; y++) {
		for (int x = 0; x < width_; x++) {
			field_.push_back(Cell(x, y, CellState::EMPTY));
		}
	}
	randomizeField();
	aliveShipCount_ = shipCount_;
}

Player::~Player() {}

string Player::getName() {
	return name_;
}

int Player::getWidth() {
	return width_;
}

int Player::getHeight() {
	return height_;
}

void Player::setName(const string& name) {
	name_ = name;
}

bool Player::randomizeField() {
	srand(time(0));
	int deckCount = 4;
	int shipCount = 1;
	int xPosition;
	int yPosition;
	bool isHorizontal;
	for (deckCount; deckCount > 0; deckCount--, shipCount++) {
		for (int count = 0; count < shipCount; count++) {
			do {
				isHorizontal = rand() % 2 == 0;
				xPosition = rand() % width_;
				yPosition = rand() % height_;
			} while (isUnavailable(xPosition, yPosition, isHorizontal, deckCount));
			vector<Cell> cells;
			for (int i = 0; i < deckCount; i++) {
				field_.at(xPosition + height_ * yPosition).setCellState(CellState::CLEAN);
				cells.push_back(Cell(xPosition, yPosition, CellState::CLEAN));
				if (isHorizontal) {
					xPosition++;
				}
				else {
					yPosition++;
				}
			}
			ships_.push_back(Ship(deckCount, cells));
		}
	}

	return true;
}

bool Player::isUnavailable(int xPosition, int yPosition, bool isHorizontal, int deckCount) {
	int topBorder, leftBorder, bottomBorder, rightBorder;
	if (xPosition == 0) {
		leftBorder = xPosition;
		rightBorder = xPosition + 1;
	}
	else if (xPosition == width_ - 1) {
		leftBorder = xPosition - 1;
		rightBorder = xPosition;
	}
	else {
		leftBorder = xPosition - 1;
		rightBorder = xPosition + 1;
	}
	if (yPosition == 0) {
		topBorder = yPosition;
		bottomBorder = yPosition + 1;
	}
	else if (yPosition == height_ - 1) {
		topBorder = yPosition - 1;
		bottomBorder = yPosition;
	}
	else {
		topBorder = yPosition - 1;
		bottomBorder = yPosition + 1;
	}

	if (isHorizontal) {
		if (rightBorder + deckCount > width_ - 1)
			return true;
		for (int y = topBorder; y <= bottomBorder; y++) {
			for (int x = leftBorder; x <= rightBorder + deckCount; x++) {
				if (field_.at(x + height_ * y).getCellState() != EMPTY)
					return true;
			}
		}
		return false;
	}
	else {
		if (bottomBorder + deckCount > height_ - 1)
			return true;
		for (int y = topBorder; y <= bottomBorder + deckCount; y++) {
			for (int x = leftBorder; x <= rightBorder; x++) {
				if (field_.at(x + height_ * y).getCellState() != EMPTY)
					return true;
			}
		}
		return false;
	}
}

bool Player::shut(int x, int y) {
	switch (field_.at(x + height_ * y).getCellState()) {
	case CLEAN:
		field_.at(x + height_ * y).setCellState(CellState::SHOT);
		return true;
	case EMPTY:
		field_.at(x + height_ * y).setCellState(CellState::MISSED);
		return false;
	default:
		return false;
	}
}

int Player::getAliveShipCount() {
	return aliveShipCount_;
}

vector<Cell> Player::getField() {
	return field_;
}