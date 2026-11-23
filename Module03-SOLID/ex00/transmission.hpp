#pragma once

class Transmission
{
	private:
		int gearLevel; // -1 = reverse, 0 = neutral position, max 5

	public:
		Transmission();
		~Transmission();

		void shift_gears_up();
		void shift_gears_down();
		void reverse();

		int get_gear_level() const;
};