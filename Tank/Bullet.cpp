#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(AssetManager& asset, const sf::Vector2f& position, const sf::Vector2f& direction, float speed)
{
	asset.LoadTexture("bullet", "resources/gameState/bullet.png");
	this->sprite.setTexture(asset.GetTexture("bullet"));
	this->sprite.setPosition(position.x, position.y);
	this->sprite.scale(0.2, 0.2);
	this->direction = direction;
	this->movementSpeed = speed;
}

Bullet::~Bullet() {}

sf::FloatRect Bullet::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Bullet::update()
{
	this->sprite.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}


