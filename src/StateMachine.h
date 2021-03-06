#pragma once
#include "Game.h"

#include <string>
#include <stack>
#include <memory>

class State
{
public:
	virtual ~State() {};
	virtual void Update(float) {};
	virtual void Render() {};
	virtual void ProcessInput() {};
	virtual void OnEnter() {};
	virtual void OnExit() {};
};

class StateMachine
{
private:
	std::stack<std::unique_ptr<State>> states;
public:
	StateMachine();
	void PushState(std::unique_ptr<State> state);
	void PopState();
	void Update(float dt);
	void Render();
	void ProcessInput();
	const State& GetActiveState();
	int GetNumStates() const;
};
