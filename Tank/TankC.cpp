#include "TankC.h"



TankC::TankC()
{
}

TankC::~TankC()
{

}

const sf::Sprite& TankC::getSprite() const
{
	return this->sprite;
}

const sf::Vector2f& TankC::getPosition() const
{
	return this->sprite.getPosition();
}

void TankC::UpdateAttack()
{
	if (this->attackCooldown < 1000)
	{
		this->attackCooldown += 0.5f;
	}
}

const bool TankC::isAbleToAttack()
{
	if (this->attackCooldown >= 1000)
	{
		this->attackCooldown = 0;
		return true;
	}
	return false;
}

void TankC::setDirection()
{
	if (this->sprite.getRotation() == 0)
	{
		this->direction.x = 1.f;
		this->direction.y = 0.f;
	}
	else if(this->sprite.getRotation() == 90)
	{
		this->direction.x = 0.f;
		this->direction.y = 1.f;
	}
	else if (this->sprite.getRotation() == 180)
	{
		this->direction.x = -1.f;
		this->direction.y = 0.f;
	}
	else if (this->sprite.getRotation() == 270)
	{
		this->direction.x = 0.f;
		this->direction.y = -1.f;
	}
}

void TankC::Move(const float dirX, const float dirY)
{
}

void TankC::Shoot()
{

}
