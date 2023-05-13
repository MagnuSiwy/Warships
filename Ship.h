#pragma once

#include <vector>

enum class ShipState
{
	Placed
	, NotPlaced
};

class Ship
{
private:
	using PositionContainer = std::vector<std::pair<int, int> >;
	PositionContainer mPosition;
	int mDurability;
	ShipState mState;
public:
	Ship(int durability);
	~Ship() = default;
	const PositionContainer &getPosition() const;
	const void addPosition(int letter, int number);
	const void hit();
	const int lifePoints() const;
	const bool isDestroyed() const;
	const bool isPlaced() const;
	const void makeShipPlaced();
};

