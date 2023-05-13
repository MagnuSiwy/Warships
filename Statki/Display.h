#pragma once

#include <vector>

#include "Cell.h"
#include "Board.h"


class Display
{
private:
	std::string strInput;
public:
	Display() = default;
	virtual ~Display() = default;
	virtual const void drawBoard(Board &board1, Board &board2) const = 0;
	virtual const void drawString(std::string input) const = 0;
	virtual const void drawState(std::string input) const = 0;
	virtual const void hold() const = 0;
	virtual const std::string getPlace() = 0;
	virtual const char getChoice() = 0;
	virtual const void wrongMove() const = 0;
	virtual const void turn(const char *player) const = 0;
	virtual const void endGame(const char* player) const = 0;
	virtual const void menu() const = 0;
	virtual const void shotResult(bool hit, bool destroyed) const = 0;
};

