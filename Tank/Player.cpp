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

void Player::HandleEvents(sf::Event& event, std::vector<Bullet*>& bullets)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Move(0.f, 1.f);
		this->sprite.setRotation(90.f);
	}
	if (event.key.code == sf::Keyboard::Up)
	{
		Move(0.f, -1.f);
		this->sprite.setRotation(-90.f);
	}
	if (event.key.code == sf::Keyboard::Left)
	{
		Move(-1.f, 0.f);
		this->sprite.setRotation(-180.f);
	}
	if (event.key.code == sf::Keyboard::Right)
	{
		Move(1.f, 0.f);
		this->sprite.setRotation(0.f);
	}

	setDirection();
	Shoot(bullets);
}


void Player::Move(const float dirX, const float dirY)
{
	this->sprite.move(dirX * moveSpeed, dirY * moveSpeed);
}

void Player::Shoot(std::vector<Bullet*>& bullets)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isAbleToAttack())
	{
		bullets.push_back(new Bullet(this->data->assets, this->sprite.getPosition(), this->direction, 0.1f));

	}
	
}

void Player::Update()
{
	UpdateAttack();
}


void Player::Render()
{
	this->data->window.draw(sprite);
}
