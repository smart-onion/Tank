#include "Window.h"

GameWindow::GameWindow()
{
	SetVideoMode();
	InitWindow();
}

GameWindow::~GameWindow()
{
	delete this->window;
}

void GameWindow::InitWindow()
{
	this->window = new RenderWindow(this->videoMode, "My Game", Style::Titlebar | Style::Close | Style::Resize);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void GameWindow::SetVideoMode() { SetVideoMode(800, 600); }

void GameWindow::SetVideoMode(unsigned int width, unsigned int height)
{
	this->videoMode.height = height;
	this->videoMode.width = width;
}

VideoMode GameWindow::GetVideoMode() const
{
	return this->videoMode;
}

bool const GameWindow::WindowIsOpen() const
{
	return this->window->isOpen();
}

RenderWindow& GameWindow::GetWindow() const
{
	return *this->window;
}

void GameWindow::Render()
{
	this->window->clear();
	this->window->display();
}
