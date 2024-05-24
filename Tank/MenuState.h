#pragma once

#include "GameData.h"
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Definitions.h"
#include <SFML/System.hpp>
#include <iostream>
#include "LoadLevel.h"


class MenuState : public State
{
	std::shared_ptr<GameData> data;
	sf::Sprite background;
	sf::Text play;
	sf::Text option;
	sf::Text exit;
	sf::Sprite cursor;


	enum MenuSelected
	{
		PLAY = 0,
		OPTION = 1,
		EXIT = 2
	};

	int select;

	void CursorAnimation();

public:
	MenuState(std::shared_ptr<GameData> data);
	~MenuState();

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};

