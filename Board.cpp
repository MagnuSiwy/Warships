#include "Board.h"


const std::vector<Cell> &Board::getBoard() const
{
	return mBoard;
}

Cell &Board::getCell(int x, int y)
{
	return mBoard[x * 10 + y];
}