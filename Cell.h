#pragma once

#include <string>


enum class CellState
{
	Empty
	,Shot
	,Hit
	,Miss
	,Ship
};

class Cell
{
private:
	CellState mState = CellState::Empty;
public:
	Cell() = default;
	~Cell() = default;
	const bool isEmpty() const;
	const bool isHit() const;
	const bool isShip() const;
	const bool isMissed() const;
	const void placeShip();
	const void hitIt();
	const void missIt();
	const CellState getState() const;
};

