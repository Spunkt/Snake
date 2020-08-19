#pragma once

#include "./StateMachine.h"

enum MENU_OPTIONS
{
	START = 0,
	EXIT = 1
};

class MenuState : public State
{
private:
	void DrawInfo();
public:
	MenuState();
	void Render() override;
	void ProcessInput() override;
};
