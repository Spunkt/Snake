#include "./StateMachine.h"

StateMachine::StateMachine()
{}

StateMachine::~StateMachine()
{}

void StateMachine::PushState(std::unique_ptr<State> state)
{
	if (!this->states.empty())
	{
		this->states.top()->OnExit();
	}
	this->states.push(std::move(state));
	this->states.top()->OnEnter();
}

void StateMachine::PopState()
{
	this->states.top()->OnExit();
	this->states.pop();
}

void StateMachine::Update(float dt)
{
	if (!this->states.empty())
	{
		this->states.top()->Update(dt);
	}
}

void StateMachine::Render()
{
	if (!this->states.empty())
	{
		this->states.top()->Render();
	}
}

void StateMachine::ProcessInput()
{
	if (!this->states.empty())
	{
		this->states.top()->ProcessInput();
	}
}

const State& StateMachine::GetActiveState()
{
	return *this->states.top();
}

const std::string& StateMachine::GetActiveStateName()
{
	return this->states.top()->GetName();
}