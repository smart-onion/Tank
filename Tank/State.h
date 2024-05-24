#pragma once
class State
{
public:
	virtual void Init();
	virtual void HandleInput();
	virtual void Update(float dt);
	virtual void Draw(float dt);
	virtual void Pause();
	virtual void Resume();
};

