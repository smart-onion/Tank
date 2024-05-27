#include "GameState.h"

GameState::GameState(std::shared_ptr<GameData> data)
{
	this->data = data;
	player = std::make_unique<Player>(this->data);
}

GameState::~GameState() 
{
	for (auto* i : this->bullets)
	{
		delete i;
	}
}

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
		
		player->HandleEvents(event, bullets);
		

	}


}

void GameState::UpdateBullet()
{
	unsigned int counter = 0;

	for (auto* bullet : this->bullets)
	{
		bullet->update();

		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			delete bullet;
			bullets.erase(bullets.begin() + counter);
			counter--;
		}

		counter++;
	}
}

void GameState::Update(float dt)
{
	player->Update();

	UpdateBullet();
}

void GameState::Draw(float dt)
{
	this->data->window.clear(sf::Color::Black);
	
	// drawing here
	player->Render();

	for (auto* i : this->bullets)
	{
		i->render(this->data->window);
	}

	this->data->window.display();
}
