#pragma once

#include "State.h";
#include <memory>
#include "GameData.h"
#include "TankC.h"
#include "Player.h"

class GameState : public State
{
	std::shared_ptr<GameData> data;
	
	std::unique_ptr<Player> player;

public:
	GameState(std::shared_ptr<GameData> data);
	~GameState();


	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
