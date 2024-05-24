#pragma once

#include "Bullet.h"
#include <SFML/Graphics.hpp>

class TankC
{
protected:
	int health;
	Bullet bullet;
	sf::Sprite sprite;

public:
	TankC();
	~TankC();

	virtual void Move(const float dirX, const float dirY);
	virtual void Shoot();
};

