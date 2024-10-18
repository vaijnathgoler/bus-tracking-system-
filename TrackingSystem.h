#ifndef TRACKING_SYSTEM_H
#define TRACKING_SYSTEM_H

#include <vector>
#include <memory>
#include "Bus.h"

class TrackingSystem {
public:
    void addBus(std::unique_ptr<Bus> bus);
    void updateBusLocation(int busId, double latitude, double longitude);
    std::vector<Bus*> getAllBuses() const;
    Bus* getBusById(int id) const;

private:
    std::vector<std::unique_ptr<Bus>> buses;
};

#endif // TRACKING_SYSTEM_H