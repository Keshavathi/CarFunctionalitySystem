#include "../include/Car.h"
#include <cmath>
#include <iostream>

// Define M_PI if not defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Car::Car() : speed(0), latitude(0), longitude(0), destLat(0), destLon(0), gear(GearType::PARK) {}

void Car::accelerate(double value) {
    if (gear == GearType::DRIVE || gear == GearType::REVERSE) {
        speed += value;
    } else {
        std::cout << "Cannot accelerate unless in DRIVE or REVERSE.\n";
    }
}

void Car::brake(double value) {
    speed -= value;
    if (speed < 0) speed = 0;
}

void Car::shiftGear(GearType newGear) {
    gear = newGear;
    std::cout << "Gear shifted to ";
    switch (gear) {
        case GearType::PARK: std::cout << "PARK\n"; break;
        case GearType::REVERSE: std::cout << "REVERSE\n"; break;
        case GearType::NEUTRAL: std::cout << "NEUTRAL\n"; break;
        case GearType::DRIVE: std::cout << "DRIVE\n"; break;
    }
}

GearType Car::getGearState() const {
    return gear;
}

double Car::getSpeed() const {
    return speed;
}

std::pair<double, double> Car::getLocation() const {
    return {latitude, longitude};
}

std::pair<double, double> Car::getDestination() const {
    return {destLat, destLon};
}

void Car::setDestination(double lat, double lon) {
    destLat = lat;
    destLon = lon;
    std::cout << "Destination set to (" << destLat << ", " << destLon << ")\n";
}

void Car::drive(double time) {
    if (speed <= 0) {
        std::cout << "Speed is zero. Cannot drive.\n";
        return;
    }

    std::cout << "Driving for " << time << " hours...\n";
    double distance = speed * time;
    double totalDistance = calculateDistance(latitude, longitude, destLat, destLon);

    if (distance >= totalDistance) {
        latitude = destLat;
        longitude = destLon;
        std::cout << "The car has reached its destination.\n";
        std::cout << "Distance covered: " << totalDistance << " km\n";
    } else {
        double ratio = distance / totalDistance;
        latitude += (destLat - latitude) * ratio;
        longitude += (destLon - longitude) * ratio;
        std::cout << "Distance covered: " << distance << " km\n";
    }
}

double Car::timeToDestination() const {
    if (speed <= 0) return -1;
    double remaining = calculateDistance(latitude, longitude, destLat, destLon);
    return remaining / speed;
}

bool Car::hasArrived() const {
    return (std::abs(latitude - destLat) < 1e-4) && (std::abs(longitude - destLon) < 1e-4);
}

double Car::getRemainingDistance() const {
    return calculateDistance(latitude, longitude, destLat, destLon);
}

// Haversine formula
double Car::calculateDistance(double lat1, double lon1, double lat2, double lon2) const {
    constexpr double R = 6371.0; // Radius of Earth in km
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 *= M_PI / 180.0;
    lat2 *= M_PI / 180.0;

    double a = std::pow(std::sin(dLat / 2), 2) +
               std::pow(std::sin(dLon / 2), 2) * std::cos(lat1) * std::cos(lat2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return R * c;
}
