#include "car.hpp"

Car::Car() {}

Car::~Car() {}



void Car::start() {
	_engine.start();
}
void Car::stop() {
	_engine.stop();
	_brakes.apply_emergency_brakes();
}
void Car::accelerate(float speed) {
	_engine.accelerate(speed);
}
bool Car::is_engine_running() const {
	return _engine.is_engine_running();
}
float Car::get_current_speed() const {
	return _engine.get_current_speed();
}


void Car::shift_gears_up() {
	_transmission.shift_gears_up();
}
void Car::shift_gears_down() {
	_transmission.shift_gears_down();
}
void Car::reverse() {
	_transmission.reverse();
}
int Car::get_gear_level() const {
	return _transmission.get_gear_level();
}



void Car::turn_wheel(float angle) {
	_steering.turn_wheel(angle);
}
void Car::straighten_wheels() {
	_steering.straighten_wheels();
}
float Car::get_wheel_angle() const {
	return _steering.get_wheel_angle();
}



void Car::apply_force_on_brakes(float force) {
	_brakes.apply_force_on_brakes(force);
}
void Car::apply_emergency_brakes() {
	_brakes.apply_emergency_brakes();
}
float Car::get_current_force() const {
	return _brakes.get_current_force();
}