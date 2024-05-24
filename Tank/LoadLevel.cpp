#include "LoadLevel.h"



LoadLevel::LoadLevel(std::shared_ptr<GameData> data)
{
	this->data = data;
	Init();
}

LoadLevel::~LoadLevel() {}

void LoadLevel::BackgroundAnimation()
{
	if (animationScale < 10) animationScale += 0.005;
	background.setScale(SCREEN_WIDTH, animationScale);
}

void LoadLevel::Init()
{
	this->data->assets.LoadTexture("loadLevelBG", "resources/level/background.png");
	background.setTexture(this->data->assets.GetTexture("loadLevelBG"));
	background.setPosition(0, 0);
	background.setScale(SCREEN_WIDTH, 0);

	text.setFont(this->data->assets.GetFont("PixeloidMono"));
	text.setString("Level 1");
	text.setFillColor(sf::Color::Black);
	text.setPosition(SCREEN_WIDTH / 2 - text.getGlobalBounds().width / 2, SCREEN_HIEGHT * 0.4);
}

void LoadLevel::HandleInput()
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

void LoadLevel::Update(float dt)
{
	if (animationScale > 10)
	{
		sf::sleep(sf::seconds(2));
		this->data->machine.AddState(StateRef(new GameState(this->data)));

	}
}

void LoadLevel::Draw(float dt)
{
	this->data->window.clear();
	BackgroundAnimation();
	this->data->window.draw(background);
	if (animationScale > 10)
	{
		this->data->window.draw(text);
	}
	this->data->window.display();
}
