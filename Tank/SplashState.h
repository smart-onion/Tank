#pragma once
#include "GameData.h"
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Definitions.h"
#include <iostream>
#include "MenuState.h"

class SplashState : public State
{
	std::shared_ptr<GameData> data;
	sf::Clock clock;
	sf::Sprite background;

public:
	SplashState(std::shared_ptr<GameData> data);
	~SplashState();


	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

};

