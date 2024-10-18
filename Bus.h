#ifndef BUS_H
#define BUS_H

#include <string>
#include "GPS.h"

class Bus {
public:
    Bus(int id, const std::string& route);
    void updateLocation(double latitude, double longitude);
    int getId() const;
    std::string getRoute() const;
    GPS getLocation() const;

private:
    int id;
    std::string route;
    GPS location;
};

#endif // BUS_H