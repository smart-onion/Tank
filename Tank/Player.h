#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "TankC.h"
#include <memory>
#include "GameData.h"
#include <iostream>
#include "Bullet.h"

class Player : public TankC
{
	std::shared_ptr<GameData> data;


public:
	Player(std::shared_ptr<GameData> data);
	~Player();

	void HandleEvents(sf::Event& event, std::vector<Bullet*>& bullet);

	void Move(const float dirX, const float dirY);
	void Shoot(std::vector<Bullet*>& bullet);
	void Update();
	void Render();
};
#endif // !PLAYER_H