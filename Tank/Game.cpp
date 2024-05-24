#include "Game.h"

// constructors and destructors
Game::Game(unsigned int width, unsigned int height, std::string title)
{
	this->data = std::make_shared<GameData>();
	this->data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	this->data->machine.AddState(StateRef(new SplashState(this->data)));
	Run();
}

Game::~Game()
{

}

void Game::Run()
{
	while (this->data->window.isOpen())
	{
		this->data->machine.ProcessStateChanges();
		this->data->machine.GetActiveState()->HandleInput();
		this->data->machine.GetActiveState()->Update(dt);
		this->data->machine.GetActiveState()->Draw(dt);
	}
}
