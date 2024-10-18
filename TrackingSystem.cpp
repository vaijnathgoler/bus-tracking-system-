#include "TrackingSystem.h"
#include <algorithm>

void TrackingSystem::addBus(std::unique_ptr<Bus> bus) {
    buses.push_back(std::move(bus));
}

void TrackingSystem::updateBusLocation(int busId, double latitude, double longitude) {
    auto it = std::find_if(buses.begin(), buses.end(),
                           [busId](const std::unique_ptr<Bus>& bus) { return bus->getId() == busId; });
    if (it != buses.end()) {
        (*it)->updateLocation(latitude, longitude);
    }
}

std::vector<Bus*> TrackingSystem::getAllBuses() const {
    std::vector<Bus*> result;
    for (const auto& bus : buses) {
        result.push_back(bus.get());
    }
    return result;
}

Bus* TrackingSystem::getBusById(int id) const {
    auto it = std::find_if(buses.begin(), buses.end(),
                           [id](const std::unique_ptr<Bus>& bus) { return bus->getId() == id; });
    return (it != buses.end()) ? it->get() : nullptr;
}