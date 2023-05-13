#include <cstdlib>

#include "InputCheck.h"
#include "Cell.h"

const bool InputCheck::checkPlace(std::string& input) const
{
	bool possibleLetter = false;
	bool possibleNumber = false;

	if (input.length() != 2)
	{
		return false;
	}

	for (auto k : { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' })
	{
		if (toupper(input[0]) == k)
		{
			possibleLetter = true;
			break;
		}
	}
	for (auto k : { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' })
	{
		if (input[1] == k)
		{
			possibleNumber = true;
			break;
		}
	}

	if (possibleLetter && possibleNumber)
	{
		return true;
	}

	return false;
}

const bool InputCheck::isPartOfShip(char letter, int number, Ship& ship) const
{
	if (!ship.getPosition().empty())
	{
		const std::pair<int, int>& front = ship.getPosition().front();
		const std::pair<int, int>& back = ship.getPosition().back();

		if (front.first == letter && front.second == number)
		{
			return true;
		}

		if (back.first == letter && back.second == number)
		{
			return true;
		}
	}

	return false;
}

const bool InputCheck::canPlaceShip(char letter, int number, Board& board, Ship& ship)
{
	const auto& size = ship.getPosition().size();

	if (!board.getCell(letter, number).isEmpty())
	{
		return false;
	}

	if (letter + 70 != 'J')
	{
		if (board.getCell(letter + 1, number).isShip())
		{
			if(!isPartOfShip(letter + 1, number, ship))
			{
				return false;
			}
		}
	}

	if (letter + 70 != 'A')
	{
		if (board.getCell(letter - 1, number).isShip())
		{
			if (!isPartOfShip(letter - 1, number, ship))
			{
				return false;
			}
		}
	}

	if (number - 2 != '9')
	{
		if (board.getCell(letter, number + 1).isShip())
		{
			if (!isPartOfShip(letter, number + 1, ship))
			{
				return false;
			}
		}
	}

	if (number - 2 != '0')
	{
		if (board.getCell(letter, number - 1).isShip())
		{
			if (!isPartOfShip(letter, number - 1, ship))
			{
				return false;
			}
		}
	}


	if (size == 0)
	{
		return true;
	}

	const std::pair<int, int>& front = ship.getPosition().front();
	const std::pair<int, int>& back = ship.getPosition().back();

	if (size == 1 && (abs(letter - front.first) == 1 || abs(number - front.second) == 1))
	{
		return true;
	}

	//letter change
	if (abs(front.first - back.first) == size - 1 && (abs(letter - front.first) == 1 || abs(letter - back.first) == 1) && number == front.second)
	{
		return true;
	}

	//number change
	if (abs(front.second - back.second) == size - 1 && (abs(number - front.second) == 1 || abs(number - back.second) == 1) && (letter == front.first))
	{
		return true;
	}

	return false;
}

const bool InputCheck::canShoot(char letter, int number, Board& board)
{
	Cell& cell = board.getCell(letter, number);

	if (cell.isEmpty() || cell.isShip())
	{
		return true;
	}

	return false;
}