#include <algorithm>

#include "Ship.h"


Ship::Ship(int durability) : 
	mDurability(durability)
	, mState(ShipState::NotPlaced)
{}

const Ship::PositionContainer &Ship::getPosition() const
{
	return mPosition;
}

const void Ship::addPosition(int letter, int number)
{
	mPosition.emplace_back(letter, number);
	std::sort(mPosition.begin(), mPosition.end());
}

const void Ship::hit()
{
	--mDurability;
}

const int Ship::lifePoints() const
{
	return mDurability;
}

const bool Ship::isDestroyed() const
{
	if (mDurability <= 0)
	{
		return true;
	}

	return false;
}

const bool Ship::isPlaced() const
{
	if (mState == ShipState::Placed)
	{
		return true;
	}

	return false;
}

const void Ship::makeShipPlaced()
{
	mState = ShipState::Placed;
}