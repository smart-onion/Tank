#include "Player.h"

Player::Player(std::shared_ptr<GameData> data)
{
	this->data = data;

	this->data->assets.LoadTexture("player", "resources/menu/cursor1.png");
	sprite.setTexture(this->data->assets.GetTexture("cursor1"));
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	
	moveSpeed = 5.f;
}

Player::~Player()
{
}


void Player::Rotate(sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Up)
	{
		this->sprite.setRotation(-90.f);
	}

	if (event.key.code == sf::Keyboard::Down)
	{
		this->sprite.setRotation(90.f);
	}
	if (event.key.code == sf::Keyboard::Left)
	{
		this->sprite.setRotation(-180.f);
	}
	if (event.key.code == sf::Keyboard::Right)
	{
		this->sprite.setRotation(0.f);
	}
}

void Player::Move(const float dirX, const float dirY)
{
	this->sprite.move(dirX * moveSpeed, dirY * moveSpeed);
}

void Player::Shoot()
{
}

void Player::Update()
{
}


void Player::Render()
{
	this->data->window.draw(sprite);
}
