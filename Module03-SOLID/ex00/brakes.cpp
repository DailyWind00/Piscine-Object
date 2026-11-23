#include "brakes.hpp"

Brakes::Brakes()
{
	currentForce = 0;
}

Brakes::~Brakes() {}



void Brakes::apply_force_on_brakes(float force)
{
	currentForce = force;

	if (currentForce > 10) currentForce = 10;
	if (currentForce <  0) currentForce =  0;
}

void Brakes::apply_emergency_brakes()
{
	currentForce = 10;
}



float Brakes::get_current_force() const
{
	return currentForce;
}