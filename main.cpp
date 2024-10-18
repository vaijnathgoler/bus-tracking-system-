#include <iostream>
#include <memory>
#include "TrackingSystem.h"

int main() {
    TrackingSystem system;

    // Add some buses
    system.addBus(std::make_unique<Bus>(1, "Route A"));
    system.addBus(std::make_unique<Bus>(2, "Route B"));
    system.addBus(std::make_unique<Bus>(3, "Route C"));

    // Simulate GPS updates
    system.updateBusLocation(1, 40.7128, -74.0060); // New York City
    system.updateBusLocation(2, 34.0522, -118.2437); // Los Angeles
    system.updateBusLocation(3, 41.8781, -87.6298); // Chicago

    // Print all bus locations
    for (const auto& bus : system.getAllBuses()) {
        std::cout << "Bus " << bus->getId() << " on " << bus->getRoute()
                  << " is at location (" << bus->getLocation().getLatitude()
                  << ", " << bus->getLocation().getLongitude() << ")" << std::endl;
    }

    return 0;
}