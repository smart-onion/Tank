#ifndef BULLET_H
#define BULLET_H

#include "AssetManager.h"

class Bullet
{
	sf::Sprite sprite;
	sf::Vector2f direction;
	float movementSpeed;

public:
	// c-tor / d-tor
	Bullet();
	Bullet(AssetManager& asset, const sf::Vector2f& position, const sf::Vector2f& direction, float speed);
	~Bullet();

	sf::FloatRect getBounds() const;

	void update();

	void render(sf::RenderWindow& window);
};
#endif // BULLET_H
