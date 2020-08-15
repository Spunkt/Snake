#pragma once
#include "Game.h"

#include <string>
#include <stack>
#include <memory>

class State
{
private:
	std::string m_Name;
public:
	virtual const std::string& GetName() { return this->m_Name; };
	virtual void SetName(const std::string& name) { this->m_Name = name; };
	virtual ~State() {};
	virtual void OnEnter() {};
	virtual void OnExit() {};
	virtual void Update(float) {};
	virtual void Render() {};
	virtual void ProcessInput() {};
};

class StateMachine
{
private:
	std::stack<std::unique_ptr<State>> states;
public:
	StateMachine();
	~StateMachine();
	void PushState(std::unique_ptr<State> state);
	void PopState();
	void Update(float dt);
	void Render();
	void ProcessInput();
	const State& GetActiveState();
	const std::string& GetActiveStateName();
};