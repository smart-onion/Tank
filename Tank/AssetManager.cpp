#include "AssetManager.h"

AssetManager::AssetManager() {}

AssetManager::~AssetManager() {}

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;
	if (texture.loadFromFile(fileName))
	{
		this->textures[name] = texture;
	}
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
	return this->textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName))
	{
		this->fonts[name] = font;
	}
}

sf::Font& AssetManager::GetFont(std::string name)
{
	return this->fonts.at(name);
}
