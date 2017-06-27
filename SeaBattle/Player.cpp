#include <ctime>

#include "Helper.h"
#include "Player.h"

Player::Player(const string& name) : name_(name)
{
	Helper helper;
	width_ = helper.getFieldWidth();
	height_ = helper.getFieldHeight();
	shipCount_ = helper.getShipCount();
	for (int y = 0; y < height_; y++) {
		for (int x = 0; x < width_; x++) {
			field_.push_back(Cell(x, y, CellState::EMPTY));
		}
	}
	randomizeField();
	aliveShipCount_ = shipCount_;
}

Player::~Player() {}

string Player::getName() const {
	return name_;
}

int Player::getWidth() const {
	return width_;
}

int Player::getHeight() const {
	return height_;
}

void Player::setName(const string& name) {
	name_ = name;
}

bool Player::randomizeField() {
	//srand(time(0));
	Helper helper;
	int deckCount = helper.getInitDeckCount();
	int shipCount = helper.getInitShipCount();
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
	int topBorder = 0, leftBorder = 0, bottomBorder = height_ - 1, rightBorder = width_ - 1;
	if (xPosition == 0) {
		rightBorder = xPosition + 1;
	}
	else if (xPosition == width_ - 1) {
		leftBorder = xPosition - 1;
	}
	else {
		leftBorder = xPosition - 1;
		rightBorder = xPosition + 1;
	}
	if (yPosition == 0) {
		bottomBorder = yPosition + 1;
	}
	else if (yPosition == height_ - 1) {
		topBorder = yPosition - 1;
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

bool Player::isShot(int x, int y) {
	for (int i = 0; i < shipCount_; i++) {
		if (ships_.at(i).isShot(x, y)) {
			field_.at(x + height_ * y).setCellState(CellState::SHOT);/*?*/
			if (ships_.at(i).getHealth() == 0) {//mark killed ship
				auto decks = ships_.at(i).getDecks();
				bool isHorizontal = (decks.size() > 1) && (decks.at(1).getXPosition() == decks.at(0).getXPosition() + 1);
				int topBorder = 0, leftBorder = 0, bottomBorder = height_ - 1, rightBorder = width_ - 1;
				if (decks.at(0).getXPosition() != 0) {
					leftBorder = decks.at(0).getXPosition() - 1;
				}
				if (decks.at(0).getYPosition() != 0) {
					topBorder = decks.at(0).getYPosition() - 1;
				}
				if (isHorizontal) {
					if (decks.at(decks.size() - 1).getXPosition() != width_ - 1) {
						rightBorder = decks.at(decks.size() - 1).getXPosition() + 1;
					}
					if (decks.at(0).getYPosition() != height_ - 1) {
						bottomBorder = decks.at(0).getYPosition() + 1;
					}
				}
				else {
					if (decks.at(0).getXPosition() != width_ - 1) {
						rightBorder = decks.at(0).getXPosition() + 1;
					}
					if (decks.at(decks.size() - 1).getYPosition() != height_ - 1) {
						bottomBorder = decks.at(decks.size() - 1).getYPosition() + 1;
					}
				}
				for (int i = leftBorder; i <= rightBorder; i++) {
					if (topBorder != decks.at(0).getYPosition()) {
						field_.at(i + height_ * topBorder).setCellState(CellState::MISSED);
					}
					if (bottomBorder != decks.at(decks.size() - 1).getYPosition()) {
						field_.at(i + height_ * bottomBorder).setCellState(CellState::MISSED);
					}
				}
				for (int i = topBorder; i <= bottomBorder; i++) {
					if (leftBorder != decks.at(0).getXPosition()) {
						field_.at(leftBorder + height_ * i).setCellState(CellState::MISSED);
					}
					if (rightBorder != decks.at(decks.size() - 1).getXPosition()) {
						field_.at(rightBorder + height_ * i).setCellState(CellState::MISSED);
					}
				}
				aliveShipCount_--;
			}
			return true;
		}
	}
	field_.at(x + height_ * y).setCellState(CellState::MISSED);/*?*/
	return false;
}

int Player::getAliveShipCount() const {
	return aliveShipCount_;
}

const vector<Cell>& Player::getField() const {
	return field_;
}