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
	this->data->assets.LoadTexture("battlecity_text", "resources/menu/battlecity_text.png");
	background.setTexture(this->data->assets.GetTexture("battlecity_text"));
	background.scale(0.8, 0.8);
	background.setPosition(SCREEN_WIDTH / 2 - background.getGlobalBounds().width / 2, SCREEN_HIEGHT * 0.1);
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
	this->data->window.clear(sf::Color::Black);
	this->data->window.draw(this->background);
	this->data->window.display();
}
