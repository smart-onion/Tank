#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Definitions.h"
#include "SplashState.h"
#include "GameData.h"
#include "MenuState.h"



class Game
{
	const float dt = 1.0f / 60.0f;
	sf::Clock clock;
	std::shared_ptr<GameData> data;

	void Run();

public:
	Game(unsigned int width, unsigned int height, std::string title);
	~Game();


};

