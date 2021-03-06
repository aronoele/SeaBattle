#include "Cell.h"
#include "CellState.h"

Cell::Cell(int x, int y, CellState state) : xPosition_(x), yPosition_(y), state_(state) {}

Cell::Cell(int x, int y) : Cell(x, y, CellState::EMPTY) {}

Cell::~Cell() {}

CellState Cell::getCellState() const {
	return state_;
}

void Cell::setCellState(CellState state) {
	state_ = state;
}

int Cell::getXPosition() const {
	return xPosition_;
}

int Cell::getYPosition() const {
	return yPosition_;
}

bool Cell::isShot() {
	bool isShot = false;
	switch (getCellState()) {
	case CLEAN:
		setCellState(CellState::SHOT);
		isShot = true;
		break;
	case EMPTY:
		setCellState(CellState::MISSED);
		isShot = false;
		break;
	default:
		isShot = false;
		break;
	}
	return isShot;
}