#include <iostream>
#include <limits>
#include <ios>
#include <stdlib.h>

#include "DisplayCmd.h"


const void DisplayCmd::drawBoard(Board &board1, Board &board2) const
{
	system("CLS");
	std::cout << "Your board \t\t Enemy board" << std::endl;

	char letter = 'A';

	std::cout << "  0 1 2 3 4 5 6 7 8 9 \t  0 1 2 3 4 5 6 7 8 9" << std::endl;

	for (int i = 0; i < 10; ++i, ++letter)
	{
		std::cout << letter;
		for (int j = 0; j < 10; ++j)
		{
			std::cout << ' ';

			Cell& cell = board1.getCell(i, j);
			switch (cell.getState())
			{
				case CellState::Empty:
				{
					std::cout << '-';
					break;
				}
				case CellState::Ship:
				{
					std::cout << 'O';
					break;
				}
				case CellState::Hit:
				{
					std::cout << 'X';
				}
				case CellState::Miss:
				{
					std::cout << '#';
				}
			}
		}

		std::cout << "\t";

		std::cout << letter;
		for (int j = 0; j < 10; ++j)
		{
			std::cout << ' ';

			Cell& cell = board2.getCell(i, j);
			switch (cell.getState())
			{
				case CellState::Shot:
				{
					std::cout << 'X';
					break;
				}
				case CellState::Miss:
				{
					std::cout << '#';
					break;
				}
				default:
				{
					std::cout << '-';
				}
			}
		}

		std::cout << std::endl;
	}
}

const void DisplayCmd::drawString(std::string input) const
{
	std::cout << input << std::endl;
}

const void DisplayCmd::drawState(std::string input) const
{
	std::cout << input << std::endl;
	std::cout << "Press any key..." << std::endl;
	getchar();
}

const void DisplayCmd::clrBuffer() const
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const void DisplayCmd::hold() const
{
	std::cout << "Press any key..." << std::endl;
	getchar();
}

const std::string DisplayCmd::getPlace()
{
	std::cin >> strInput;
	clrBuffer();

	return strInput;
}

const char DisplayCmd::getChoice()
{
	std::cin >> strInput;
	clrBuffer();

	return strInput[0];
}

const void DisplayCmd::wrongMove() const
{
	std::cout << "Wrong Move! Try again \nPress any key..." << std::endl;
	getchar();
}

const void DisplayCmd::turn(const char *player) const
{
	system("CLS");
	std::cout << "Player" << player << "turn";
	getchar();
}

const void DisplayCmd::endGame(const char* player) const
{
	std::cout << std::endl << "Player" << player << "won!";
	getchar();
}

const void DisplayCmd::menu() const
{
	system("CLS");
	std::cout << "1. Play against other player" << std::endl;
	std::cout << "2. Quit" << std::endl;
}

const void DisplayCmd::shotResult(bool hit, bool destroyed) const
{
	if (destroyed)
	{
		std::cout << "Enemy ship has been sunk!" << std::endl;
		getchar();
		return;
	}

	if (hit)
	{
		std::cout << "Enemy ship hit" << std::endl;
	}
	else
	{
		std::cout << "Enemy ship missed" << std::endl;
	}

	getchar();
}