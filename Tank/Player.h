#pragma once
#include <SFML/Graphics.hpp>
#include "TankC.h"
#include <memory>
#include "GameData.h"
#include <iostream>

class Player : public TankC
{
	std::shared_ptr<GameData> data;

	float moveSpeed;

public:
	Player(std::shared_ptr<GameData> data);
	~Player();

	void Rotate(sf::Event& event);
	void Move(const float dirX, const float dirY);
	void Shoot();
	void Update();
	void Render();
};

