#ifndef CAR_H
#define CAR_H

#include <utility>

enum class GearType {
    PARK = 0,
    REVERSE,
    NEUTRAL,
    DRIVE
};

class Car {
private:
    double speed;
    double latitude, longitude;
    double destLat, destLon;
    GearType gear;

    double calculateDistance(double lat1, double lon1, double lat2, double lon2) const;

public:
    Car();

    void accelerate(double value);
    void brake(double value);
    void shiftGear(GearType newGear);

    GearType getGearState() const;
    double getSpeed() const;
    std::pair<double, double> getLocation() const;
    std::pair<double, double> getDestination() const;

    void setDestination(double lat, double lon);
    void drive(double time); // time in hours
    double timeToDestination() const;
    bool hasArrived() const;

    double getRemainingDistance() const;
};

#endif
