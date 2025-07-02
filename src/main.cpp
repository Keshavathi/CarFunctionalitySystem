#include <iostream>
#include <utility>  
#include <limits>
#include "../include/Car.h"

void showMenu() {
    std::cout << "\n===== Car Functionality System =====\n";
    std::cout << "1. Shift Gear\n";
    std::cout << "2. Set Destination\n";
    std::cout << "3. Accelerate\n";
    std::cout << "4. Brake\n";
    std::cout << "5. Drive\n";
    std::cout << "6. Get Speed\n";
    std::cout << "7. Get Gear State\n";
    std::cout << "8. Get Current Location\n";
    std::cout << "9. Time to Destination\n";
    std::cout << "10. Has Arrived\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Car myCar;
    int choice;
    bool running = true;

    std::string gearNames[] = { "PARK", "REVERSE", "NEUTRAL", "DRIVE" };

    while (running) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int gear;
                std::cout << "Enter Gear (0-PARK, 1-REVERSE, 2-NEUTRAL, 3-DRIVE): ";
                std::cin >> gear;
                myCar.shiftGear(static_cast<GearType>(gear));
                break;
            }
            case 2: {
                double lat, lon;
                std::cout << "Enter destination latitude: ";
                std::cin >> lat;
                std::cout << "Enter destination longitude: ";
                std::cin >> lon;
                myCar.setDestination(lat, lon);
                break;
            }
            case 3: {
                double acc;
                std::cout << "Enter acceleration value: ";
                std::cin >> acc;
                myCar.accelerate(acc);
                std::cout << "Accelerating... Speed is now " << myCar.getSpeed() << " km/h\n";
                break;
            }
            case 4: {
                double brake;
                std::cout << "Enter brake force value: ";
                std::cin >> brake;
                myCar.brake(brake);
                std::cout<<"Braking... Speed is now "<<myCar.getSpeed() << " km/h\n";
                break;
            }
            case 5: {
                double time;
                std::cout << "Enter driving time in hours: ";
                std::cin >> time;
                myCar.drive(time);
                break;
            }
            case 6: {
                std::cout << "Current Speed: " << myCar.getSpeed() << " km/h\n";
                break;
            }
            case 7: {
                GearType gear = myCar.getGearState();
                std::cout << "Current Gear: " << gearNames[static_cast<int>(gear)] << "\n";
                break;
            }
            case 8: {
               std::pair<double, double> location = myCar.getLocation();
               std::cout << "Current Location: (" << location.first << ", " << location.second << ")\n";
                break;
            }
            case 9: {
                double time = myCar.timeToDestination();
                if (time >= 0)
                    std::cout << "Estimated time to destination: " << time << " hrs\n";
                else
                    std::cout << "Speed is zero. Cannot calculate time.\n";
                break;
            }
            case 10: {
                if (myCar.hasArrived())
                    std::cout << "The car has reached its destination.\n";
                else
                    std::cout << "The car has not arrived yet.\n";
                break;
            }
            case 0: {
                running = false;
                break;
            }
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
