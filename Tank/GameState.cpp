#include "GameState.h"

GameState::GameState(std::shared_ptr<GameData> data)
{
	this->data = data;
	player = std::make_unique<Player>(this->data);
}

GameState::~GameState() {}

void GameState::Init()
{
}

void GameState::HandleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}
		
		if (sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Down)
			{
				player->Move(0.f, 1.f);
			}
			if (event.key.code == sf::Keyboard::Up)
			{
				player->Move(0.f, -1.f);
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				player->Move(-1.f, 0.f);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				player->Move(1.f, 0.f);
			}
			player->Rotate(event);

		}
	
	}


}

void GameState::Update(float dt)
{
	player->Update();
}

void GameState::Draw(float dt)
{
	this->data->window.clear(sf::Color::Black);
	
	// drawing here
	player->Render();

	this->data->window.display();
}
