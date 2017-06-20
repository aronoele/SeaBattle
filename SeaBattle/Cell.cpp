#include "Cell.h"
#include "CellState.h"

Cell::Cell(int x, int y, CellState state)
{
	xPosition_ = x;
	yPosition_ = y;
	state_ = state;
}

Cell::Cell(int x, int y) : Cell(x, y, CellState::EMPTY) {}

Cell::~Cell() {}

CellState Cell::getCellState() {
	return state_;
}

void Cell::setCellState(CellState state) {
	state_ = state;
}