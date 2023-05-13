#pragma once

#include <vector>

#include "Cell.h"
#include "Board.h"
#include "Display.h"


class DisplayCmd : public Display
{
private:
	std::string strInput;
	const void clrBuffer() const;
public:
	const void drawBoard(Board& board1, Board& board2) const override;
	const void drawString(std::string input) const override;
	const void drawState(std::string input) const override;
	const void hold() const override;
	const std::string getPlace() override;
	const char getChoice() override;
	const void wrongMove() const override;
	const void turn(const char* player) const override;
	const void endGame(const char* player) const override;
	const void menu() const override;
	const void shotResult(bool hit, bool destroyed) const override;
};

