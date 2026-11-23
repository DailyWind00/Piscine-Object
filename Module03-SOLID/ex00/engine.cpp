#include "engine.hpp"

Engine::Engine()
{
	isEngineRunning = false;
	currentSpeed = 0;
}

Engine::~Engine() {}



void Engine::start()
{
	isEngineRunning = true;
}

void Engine::stop()
{
	isEngineRunning = false;
}

void Engine::accelerate(float speed)
{
	if (isEngineRunning)
		currentSpeed += speed;
}



bool	Engine::is_engine_running() const
{
	return isEngineRunning;
}

float	Engine::get_current_speed() const
{
	return currentSpeed;
}