#pragma once

#include <vector>
#include <map>

#include "Ship.h"
#include "Board.h"
#include "Cell.h"
#include "Display.h"
#include "InputCheck.h"

class Warships
{
private:
	using ShipContainer = std::map <std::string, std::vector<Ship> >;

	static inline std::string Single = "1 - Patrol Boat";
	static inline std::string Double = "2 - Submarine";
	static inline std::string Triple = "3 - Destroyer";
	static inline std::string Quadship = "4 - Battleship";
	static inline std::string Pentaship = "5 - Carrier";

	ShipContainer mPlayerOneShips;
	ShipContainer mPlayerTwoShips;

	Display &mDisplay;
	InputCheck mChecker;

	Board mPlayerOne;
	Board mPlayerTwo;

	const void placeOne(Board& playerBoard, Board& enemyBoard, Ship& ship);
	const bool areNotPlaced(ShipContainer& ships) const;
	const int toPlace(std::vector<Ship>& ships) const;
	const void placeShips(Board& playerBoard, Board& enemyBoard, ShipContainer& ships);
	const void shoot(Board& playerBoard, Board& enemyBoard, ShipContainer& ships);
	const bool hasWon(ShipContainer& ships);
public:
	Warships(Display& display);
	~Warships() = default;
	static ShipContainer createShips();
	const void play();
};