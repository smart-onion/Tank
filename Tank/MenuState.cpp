#include "MenuState.h"



MenuState::MenuState(std::shared_ptr<GameData> data)
{
	this->data = data;
}

MenuState::~MenuState()
{
}

void MenuState::CursorAnimation()
{
	sf::sleep(sf::seconds(0.1));

	if (cursor.getTexture() == &this->data->assets.GetTexture("cursor1"))
	{
		cursor.setTexture(this->data->assets.GetTexture("cursor2"));
	}
	else
	{
		cursor.setTexture(this->data->assets.GetTexture("cursor1"));
	}
}


void MenuState::Init()
{
	// Set Background
	this->data->assets.LoadTexture("battlecity_text", "resources/menu/battlecity_text.png");
	background.setTexture(this->data->assets.GetTexture("battlecity_text"));
	background.scale(0.8, 0.8);
	background.setPosition(SCREEN_WIDTH / 2 - background.getGlobalBounds().width / 2, SCREEN_HIEGHT*0.1);

	// Set navigation
	// Play button
	this->data->assets.LoadFont("PixeloidMono", "resources/menu/fonts/PixeloidMono.ttf");
	play.setFont(this->data->assets.GetFont("PixeloidMono"));
	play.setString("PLAY");
	play.setFillColor(sf::Color::White);
	play.setPosition(SCREEN_WIDTH / 2 - play.getGlobalBounds().width / 2, SCREEN_HIEGHT * 0.5);
	
	// Option button
	option.setFont(this->data->assets.GetFont("PixeloidMono"));
	option.setString("OPTION");
	option.setFillColor(sf::Color::White);
	option.setPosition(SCREEN_WIDTH / 2 - option.getGlobalBounds().width / 2, SCREEN_HIEGHT * 0.6);


	// Exit button
	exit.setFont(this->data->assets.GetFont("PixeloidMono"));
	exit.setString("EXIT");
	exit.setFillColor(sf::Color::White);
	exit.setPosition(SCREEN_WIDTH / 2 - exit.getGlobalBounds().width / 2, SCREEN_HIEGHT * 0.7);

	// Set Cursor
	this->data->assets.LoadTexture("cursor1", "resources/menu/cursor1.png");
	this->data->assets.LoadTexture("cursor2", "resources/menu/cursor2.png");

	cursor.setTexture(this->data->assets.GetTexture("cursor1"));
	cursor.setPosition(SCREEN_WIDTH / 2 - play.getGlobalBounds().width * 2, SCREEN_HIEGHT * 0.5);

}

void MenuState::HandleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}

		if (sf::Event::KeyPressed == event.type)
		{
			if (event.key.code == sf::Keyboard::Down)
			{	
				select++;
				if (select >= 3) select = 0;
			}

			if (event.key.code == sf::Keyboard::Up)
			{
				select--;
				if (select < 0) select = 2;
			}

			cursor.setPosition(SCREEN_WIDTH / 2 - play.getGlobalBounds().width * 2, SCREEN_HIEGHT * (0.5 + float(select) / 10));

			if (event.key.code == sf::Keyboard::Enter)
			{
				switch (select)
				{
				case PLAY:
					this->data->machine.AddState(StateRef(new LoadLevel(this->data)));
					break;
				case OPTION:
					std::cout << "Go to option state";
					break;
				case EXIT:
					this->data->window.close();
					break;
				default:
					break;
				}
			}

		}
	}
}

void MenuState::Update(float dt)
{
}

void MenuState::Draw(float dt)
{
	this->data->window.clear(sf::Color::Black);
	this->data->window.draw(background);
	this->data->window.draw(play);
	this->data->window.draw(option);
	this->data->window.draw(exit);
	CursorAnimation();
	this->data->window.draw(cursor);
	this->data->window.display();

}
