#include "Bus.h"

Bus::Bus(int id, const std::string& route) : id(id), route(route) {}

void Bus::updateLocation(double latitude, double longitude) {
    location.update(latitude, longitude);
}

int Bus::getId() const {
    return id;
}

std::string Bus::getRoute() const {
    return route;
}

GPS Bus::getLocation() const {
    return location;
}