#pragma once

#include <iostream>
#include <cctype>
#include <algorithm>

#include "Warships.h"

Warships::Warships(Display& display) : mDisplay(display)
{}

Warships::ShipContainer Warships::createShips()
{
	std::vector<Ship> singleShip = { /*Ship(1), Ship(1), Ship(1), Ship(1)*/  };
	std::vector<Ship> doubleShip = { Ship(2)/*, Ship(2), Ship(2)*/ };
	std::vector<Ship> tripleShip = { Ship(3), Ship(3) };
	std::vector<Ship> quadShip = { Ship(4) };
	std::vector<Ship> pentaShip = { Ship(5) };

	ShipContainer ships = { {Single, singleShip}, {Double, doubleShip}, {Triple, tripleShip}, {Quadship, quadShip}, {Pentaship, pentaShip} };
	
	return ships;
}

const void Warships::placeOne(Board &playerBoard, Board &enemyBoard, Ship &ship)
{
	mDisplay.drawBoard(playerBoard, enemyBoard);

	for (int j = 0; j < ship.lifePoints(); ++j)
	{
		mDisplay.drawString("Choose place for your ship");
		std::string input = mDisplay.getPlace();

		if (mChecker.checkPlace(input))
		{
			char letter = (char)toupper(input[0]) - 70;
			int number = (int)input[1] + 2;

			if (mChecker.canPlaceShip(letter, number, playerBoard, ship))
			{
				playerBoard.getCell(letter, number).placeShip();
				ship.addPosition(letter, number);
			}
			else
			{
				mDisplay.wrongMove();
				j--;
			}

			mDisplay.drawBoard(playerBoard, enemyBoard);
		}
		else
		{
			mDisplay.wrongMove();
			j--;
		}
	}
}

const int Warships::toPlace(std::vector<Ship>& ships) const
{
	int counter = 0;

	for (auto& ship : ships)
	{
		if (!ship.isPlaced())
		{
			++counter;
		}
	}

	return counter;
}

const bool Warships::areNotPlaced(ShipContainer& ships) const
{
	for (auto& [_, container] : ships)
	{
		for (auto& ship : container)
		{
			if (!ship.isPlaced())
			{
				return true;
			}
		}
	}

	return false;
}

const void Warships::placeShips(Board& playerBoard, Board& enemyBoard, ShipContainer& ships)
{
	while (areNotPlaced(ships))
	{
		std::map <std::string, int> flagUsed = { {Single, toPlace(ships[Single])}, {Double, toPlace(ships[Double])}, {Triple, toPlace(ships[Triple])}, {Quadship, toPlace(ships[Quadship])}, {Pentaship, toPlace(ships[Pentaship])}};

		mDisplay.drawBoard(playerBoard, enemyBoard);
		mDisplay.drawString("Your available ships: ");
		for (auto& [name, _] : ships)
		{
			if(flagUsed[name] != 0)
			{
				mDisplay.drawString(name + " x" + std::to_string(flagUsed[name]));
			}
		}
		mDisplay.drawString("Choose one ship ");

		int choice = mDisplay.getChoice();

		switch (choice)
		{
			case '5':
			{
				if (flagUsed[Pentaship] == 0)
				{
					mDisplay.drawState("Ship already placed");
					break;
				}
				Ship& ship = ships[Pentaship][flagUsed[Pentaship] - 1];
				placeOne(playerBoard, enemyBoard, ship);
				ship.makeShipPlaced();
				break;
			}
			case '4':
			{
				if (flagUsed[Quadship] == 0)
				{
					mDisplay.drawState("Ship already placed");
					break;
				}
				Ship& ship = ships[Quadship][flagUsed[Quadship] - 1];
				placeOne(playerBoard, enemyBoard, ship);
				ship.makeShipPlaced();
				break;
			}
			case '3':
			{
				if (flagUsed[Triple] == 0)
				{
					mDisplay.drawState("Ships already placed");
					break;
				}
				Ship& ship = ships[Triple][flagUsed[Triple] - 1];
				placeOne(playerBoard, enemyBoard, ship);
				ship.makeShipPlaced();	
				break;
			}
			case '2':
			{
				if (flagUsed[Double] == 0)
				{
					mDisplay.drawState("Ships already placed");
					break;
				}
				Ship& ship = ships[Double][flagUsed[Double] - 1];
				placeOne(playerBoard, enemyBoard, ship);
				ship.makeShipPlaced();			
				break;
			}
			case '1':
			{
				if (flagUsed[Single] == 0)
				{
					mDisplay.drawState("Ships already placed");
					break;
				}
				Ship& ship = ships[Single][flagUsed[Single] - 1];
				placeOne(playerBoard, enemyBoard, ship);
				ship.makeShipPlaced();			
				break;
			}
		}
	}

	mDisplay.hold();
}

const void Warships::shoot(Board& playerBoard, Board& enemyBoard, ShipContainer& ships)
{
	bool destroyed = false, hit = false;

	while(true)
	{
		mDisplay.drawBoard(playerBoard, enemyBoard);
		mDisplay.drawString("Where would you like to shoot?");
		std::string input = mDisplay.getPlace();
	
		if (mChecker.checkPlace(input))
		{
			char letter = (char)toupper(input[0]) - 70;
			int number = (int)input[1] + 2;

			if (mChecker.canShoot(letter, number, enemyBoard))
			{
				if (enemyBoard.getCell(letter, number).isEmpty())
				{
					enemyBoard.getCell(letter, number).missIt();
					break;
				}
				else
				{
					hit = true;

					for (auto& [_, ships] : ships)
					{
						for (auto& ship : ships)
						{
							for (auto& pos : ship.getPosition())
							{
								if (pos.first == (int)letter && pos.second == number)
								{
									ship.hit();
									if (ship.isDestroyed())
									{
										destroyed = true;
									}
									break;
								}
							}
						}
					}
					enemyBoard.getCell(letter, number).hitIt();
					break;
				}
			}
			else
			{
				mDisplay.wrongMove();
			}
		}
		else
		{
			mDisplay.wrongMove();
		}
	}

	mDisplay.drawBoard(playerBoard, enemyBoard);
	mDisplay.shotResult(hit, destroyed);
}

const bool Warships::hasWon(ShipContainer& ships)
{
	for (auto& [_, ships] : ships)
	{
		for (auto& ship : ships)
		{
			if (!ship.isDestroyed())
			{
				return false;
			}
		}
	}

	return true;
}

const void Warships::play()
{
	mPlayerOneShips = createShips();
	mDisplay.turn(" one ");
	placeShips(mPlayerOne, mPlayerTwo, mPlayerOneShips);

	mPlayerTwoShips = createShips();
	mDisplay.turn(" two ");
	placeShips(mPlayerTwo, mPlayerOne, mPlayerTwoShips);

	while (true)
	{
		mDisplay.turn(" one ");
		shoot(mPlayerOne, mPlayerTwo, mPlayerTwoShips);

		if (hasWon(mPlayerTwoShips))
		{
			mDisplay.endGame(" one ");
			break;
		}

		mDisplay.turn(" two ");
		shoot(mPlayerTwo, mPlayerOne, mPlayerOneShips);

		if (hasWon(mPlayerOneShips))
		{
			mDisplay.endGame(" two ");
			break;
		}
	}
}