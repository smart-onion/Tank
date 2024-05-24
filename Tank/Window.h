#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class GameWindow
{
	RenderWindow* window;
	VideoMode videoMode;

public:

	GameWindow();
	~GameWindow();

	void InitWindow();
	void SetVideoMode();
	void SetVideoMode(unsigned int width, unsigned int height);

	// Getters
	VideoMode GetVideoMode() const;
	bool const WindowIsOpen() const;
	RenderWindow& GetWindow() const;

	void Render();
};

