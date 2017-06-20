#pragma once

#include "CellState.h"

class Cell {
public:
	Cell(int x, int y, CellState state);
	Cell(int x, int y);
	~Cell();
	CellState getCellState();
	void setCellState(CellState state);
private:
	int xPosition_;
	int yPosition_;
	CellState state_;
};
