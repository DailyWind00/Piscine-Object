#include "car.hpp"
#include <iostream>
#include <cmath>

#define PASS "\033[1;32m[PASS]\033[0m"
#define FAIL "\033[1;31m[FAIL]\033[0m"

static int testsPassed = 0;
static int testsFailed = 0;

void expect_bool(const char *name, bool actual, bool expected)
{
    if (actual == expected)
    {
        std::cout << PASS << name << std::endl;
        testsPassed++;
    }
    else
    {
        std::cout << FAIL << name
                  << " | Expected: " << expected
                  << " | Got: " << actual << std::endl;
        testsFailed++;
    }
}

void expect_int(const char *name, int actual, int expected)
{
    if (actual == expected)
    {
        std::cout << PASS << name << std::endl;
        testsPassed++;
    }
    else
    {
        std::cout << FAIL << name
                  << " | Expected: " << expected
                  << " | Got: " << actual << std::endl;
        testsFailed++;
    }
}

void expect_float(const char *name, float actual, float expected)
{
    if (std::fabs(actual - expected) < 0.001f)
    {
        std::cout << PASS << name << std::endl;
        testsPassed++;
    }
    else
    {
        std::cout << FAIL << name
                  << " | Expected: " << expected
                  << " | Got: " << actual << std::endl;
        testsFailed++;
    }
}

void print_section(const char *name)
{
    std::cout << "\n========== " << name
              << " ==========" << std::endl;
}

int main()
{
    Car car;

    // ENGINE TESTS
    print_section("ENGINE");

    expect_bool("Engine initially stopped",
                car.is_engine_running(), false);

    expect_float("Initial speed is zero",
                 car.get_current_speed(), 0.0f);

    car.accelerate(50.0f);
    expect_float("Cannot accelerate with engine stopped",
                 car.get_current_speed(), 0.0f);

    car.start();
    expect_bool("Engine starts",
                car.is_engine_running(), true);

    car.start();
    expect_bool("Starting an already running engine",
                car.is_engine_running(), true);

    car.accelerate(30.0f);
    expect_float("Accelerate by 30",
                 car.get_current_speed(), 30.0f);

    car.accelerate(20.0f);
    expect_float("Accelerate by another 20",
                 car.get_current_speed(), 50.0f);

    car.accelerate(-10.0f);
    expect_float("Negative acceleration behavior",
                 car.get_current_speed(), 40.0f);

    // TRANSMISSION TESTS
    print_section("TRANSMISSION");

    expect_int("Initial gear is neutral",
               car.get_gear_level(), 0);

    car.shift_gears_up();
    expect_int("Shift from neutral to gear 1",
               car.get_gear_level(), 1);

    car.shift_gears_up();
    car.shift_gears_up();
    car.shift_gears_up();
    car.shift_gears_up();

    expect_int("Reach maximum gear 5",
               car.get_gear_level(), 5);

    car.shift_gears_up();
    expect_int("Cannot exceed maximum gear",
               car.get_gear_level(), 5);

    car.shift_gears_down();
    expect_int("Shift down from gear 5",
               car.get_gear_level(), 4);

    car.reverse();
    expect_int("Select reverse",
               car.get_gear_level(), -1);

    car.shift_gears_down();
    expect_int("Cannot shift down below reverse",
               car.get_gear_level(), -1);

    car.shift_gears_up();
    expect_int("Shift up from reverse behavior",
               car.get_gear_level(), -1);

    // STEERING TESTS
    print_section("STEERING");

    expect_float("Initial wheel angle is zero",
                 car.get_wheel_angle(), 0.0f);

    car.turn_wheel(15.0f);
    expect_float("Turn wheels by 15 degrees",
                 car.get_wheel_angle(), 15.0f);

    car.turn_wheel(10.0f);
    expect_float("Turn wheels cumulatively",
                 car.get_wheel_angle(), 25.0f);

    car.turn_wheel(30.0f);
    expect_float("Maximum steering angle is 45",
                 car.get_wheel_angle(), 45.0f);

    car.turn_wheel(-100.0f);
    expect_float("Minimum steering angle is -45",
                 car.get_wheel_angle(), -45.0f);

    car.straighten_wheels();
    expect_float("Straighten wheels",
                 car.get_wheel_angle(), 0.0f);

    // BRAKES TESTS
    print_section("BRAKES");

    expect_float("Initial braking force is zero",
                 car.get_current_force(), 0.0f);

    car.apply_force_on_brakes(5.0f);
    expect_float("Apply braking force of 5",
                 car.get_current_force(), 5.0f);

    car.apply_force_on_brakes(3.0f);
    expect_float("Apply less braking force",
                 car.get_current_force(), 3.0f);

    car.apply_force_on_brakes(15.0f);
    expect_float("Braking force cannot exceed 10",
                 car.get_current_force(), 10.0f);

    car.apply_force_on_brakes(-20.0f);
    expect_float("Braking force cannot go below zero",
                 car.get_current_force(), 0.0f);

    car.apply_force_on_brakes(4.0f);
    car.apply_emergency_brakes();
    expect_float("Emergency brakes apply maximum force",
                 car.get_current_force(), 10.0f);

    // CAR STOP TEST
    print_section("CAR STOP");

    car.start();
    car.apply_force_on_brakes(0.0f);
    car.stop();

    expect_bool("Stop shuts down the engine",
                car.is_engine_running(), false);

    expect_float("Stop applies braking force",
                 car.get_current_force(), 10.0f);

    // SUMMARY
    print_section("TEST SUMMARY");

    std::cout << "Passed: " << testsPassed << std::endl;
    std::cout << "Failed: " << testsFailed << std::endl;
    std::cout << "Total:  " << testsPassed + testsFailed << std::endl;

    if (testsFailed == 0)
        std::cout << "\n\033[1;32mALL TESTS PASSED!\033[0m" << std::endl;
    else
        std::cout << "\n\033[1;31mSOME TESTS FAILED!\033[0m" << std::endl;

    return (testsFailed == 0 ? 0 : 1);
}