#include "transmission.hpp"

Transmission::Transmission()
{
	gearLevel = 0;
}

Transmission::~Transmission() {}



void Transmission::shift_gears_up()
{
	if (gearLevel >= 0 && gearLevel < 5)
		gearLevel++;
}

void Transmission::shift_gears_down()
{
	if (gearLevel > 0)
		gearLevel--;
}

void Transmission::reverse()
{
	if (gearLevel != -1)
		gearLevel = -1;
	else
		gearLevel = 0;
}



int Transmission::get_gear_level() const
{
	return gearLevel;
}