#ifndef CELL_H
#define CELL_H

#include "CellState.h"

class Cell {
public:
	Cell(int x, int y, CellState state);
	Cell(int x, int y);
	~Cell();
	CellState getCellState() const;
	void setCellState(CellState state);
	int getXPosition() const;
	int getYPosition() const;
	bool isShot();
private:
	int xPosition_;
	int yPosition_;
	CellState state_;
};

#endif // CELL_H
