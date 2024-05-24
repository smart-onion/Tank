#pragma once

#include "GameData.h"
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include "State.h"
#include "Definitions.h"
#include <iostream>
#include "MenuState.h"
#include "GameState.h"


class LoadLevel : public State
{
	std::shared_ptr<GameData> data;
	sf::Text text;
	sf::Sprite background;
	float animationScale;

	void BackgroundAnimation();
	sf::Clock clock;

public:
	LoadLevel(std::shared_ptr<GameData> data);
	~LoadLevel();


	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};

