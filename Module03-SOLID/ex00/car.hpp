#pragma once

# include "engine.hpp"
# include "transmission.hpp"
# include "steering.hpp"
# include "brakes.hpp"

class Car
{
	private:
		Engine			_engine;
		Transmission	_transmission;
		Steering		_steering;
		Brakes			_brakes;

	public:
		Car();
		~Car();

		void  start();
		void  stop();
		void  accelerate(float speed);
		bool  is_engine_running() const;
		float get_current_speed() const;

		void shift_gears_up();
		void shift_gears_down();
		void reverse();
		int  get_gear_level() const;

		void  turn_wheel(float angle);
		void  straighten_wheels();
		float get_wheel_angle() const;

		void  apply_force_on_brakes(float force);
		void  apply_emergency_brakes();
		float get_current_force() const;
};