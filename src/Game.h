#pragma once

#include <ncurses.h>
#include <vector>
#include <iostream>
#include <memory>

class StateMachine;

class Game
{
private:
	double m_UpdatedPerSec = 0.1;
	const unsigned int CONVERT_TO_SECONDS = 1'000'000;
public:
	Game();
	~Game();
	void Run();
	void Render();
	void Update();
	void GetInput();
	void Sleep();

	static std::unique_ptr<StateMachine> stateMachine;
	static bool s_IsRunning;
};
