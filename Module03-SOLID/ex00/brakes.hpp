#pragma once

class Brakes
{
	private:
		float currentForce; // Between 0 and 10

	public:
		Brakes();
		~Brakes();

		void apply_force_on_brakes(float force);
		void apply_emergency_brakes();

		float get_current_force() const;
};