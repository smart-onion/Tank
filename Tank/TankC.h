#pragma once

//#include "Bullet.h"
#include <SFML/Graphics.hpp>

class TankC
{
protected:
	int health;
	sf::Sprite sprite;
	sf::Vector2f direction;
	float attackCooldown = 0;
	float moveSpeed;

public:
	TankC();
	~TankC();

	const sf::Sprite& getSprite() const;

	const sf::Vector2f& getPosition() const;

	void UpdateAttack();
	const bool isAbleToAttack();
	void setDirection();

	virtual void Move(const float dirX, const float dirY);
	virtual void Shoot();
};

