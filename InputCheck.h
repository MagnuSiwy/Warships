#pragma once

#include <string>

#include "Ship.h"
#include "Board.h"


class InputCheck
{
private:
	const bool isPartOfShip(char letter, int number, Ship& ship) const;
public:
	const bool checkPlace(std::string& input) const;
	const bool canPlaceShip(char letter, int number, Board& board, Ship &ship);
	const bool canShoot(char letter, int number, Board& board);
};

