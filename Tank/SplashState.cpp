#include "SplashState.h"

SplashState::SplashState(std::shared_ptr<GameData> data)
{
	this->data = data;
	Init();
}

SplashState::~SplashState()
{
}

void SplashState::Init()
{
	this->data->assets.LoadTexture("SplashStateBG", SPLASH_SCENE_BACKGROUND_FILEPATH);
	background.setTexture(this->data->assets.GetTexture("SplashStateBG"));
	background.setPosition(0, 0);
}

void SplashState::HandleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}
	}
}

void SplashState::Update(float dt)
{
	if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		// SWitch to the main menu
		this->data->machine.AddState(StateRef(new MenuState(this->data)));
	}
}

void SplashState::Draw(float dt)
{
	this->data->window.clear(sf::Color::Red);
	this->data->window.draw(this->background);
	this->data->window.display();
}
