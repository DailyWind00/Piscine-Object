#pragma once

class Engine
{
	private:
		bool 	isEngineRunning;
		float	currentSpeed;

	public:
		Engine();
		~Engine();

		void start();
		void stop();
		void accelerate(float speed);

		bool  is_engine_running() const;
		float get_current_speed() const;
};