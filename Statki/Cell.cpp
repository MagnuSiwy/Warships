#include "Cell.h"


const bool Cell::isEmpty() const
{
	if (mState == CellState::Empty)
	{
		return true;
	}

	return false;
}

const bool Cell::isHit() const
{
	if (mState == CellState::Hit)
	{
		return true;
	}

	return false;
}

const bool Cell::isShip() const
{
	if (mState == CellState::Ship)
	{
		return true;
	}

	return false;
}

const bool Cell::isMissed() const
{
	if (mState == CellState::Miss)
	{
		return true;
	}

	return false;
}

const void Cell::placeShip()
{
	mState = CellState::Ship;
}

const void Cell::hitIt()
{
	mState = CellState::Hit;
}

const void Cell::missIt()
{
	mState = CellState::Miss;
}

const CellState Cell::getState() const
{
	return mState;
}