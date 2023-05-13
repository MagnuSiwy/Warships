#pragma once

#include <vector>
#include <string>

#include "Cell.h"


class Board
{
private:
	std::vector<Cell> mBoard{ 100 };
public:
	const std::vector<Cell> &getBoard() const;
	Cell &getCell(int x, int y);
};

