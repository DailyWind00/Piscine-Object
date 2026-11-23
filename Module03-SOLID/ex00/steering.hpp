#pragma once

class Steering
{
	private:
		float currentAngle; // Between -45° & 45°

	public:
		Steering();
		~Steering();

		void turn_wheel(float angle);
		void straighten_wheels();

		float get_wheel_angle() const;
};