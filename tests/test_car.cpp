
// Sample test case to validate acceleration and destination logic
#include "Car.h"
#include <cassert>

int main() {
    Car car;
    car.setDestination(10.0, 20.0);
    car.shiftGear(GearType::DRIVE);
    car.accelerate(60);
    car.drive(1);
    assert(car.getSpeed() == 60);
    assert(car.timeToDestination() >= 0);
    return 0;
}
