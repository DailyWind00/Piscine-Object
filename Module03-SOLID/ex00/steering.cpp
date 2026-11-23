#include "steering.hpp"

Steering::Steering()
{
	currentAngle = 0;
}

Steering::~Steering() {}



void Steering::turn_wheel(float angle)
{
	currentAngle += angle;

	if (currentAngle < -45.0f) currentAngle = -45.0f;
	if (currentAngle >  45.0f) currentAngle =  45.0f;
}

void Steering::straighten_wheels()
{
	currentAngle = 0;
}

float Steering::get_wheel_angle() const
{
	return currentAngle;
}