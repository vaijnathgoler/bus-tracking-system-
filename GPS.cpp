#include "GPS.h"

GPS::GPS() : latitude(0), longitude(0) {}

GPS::GPS(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

double GPS::getLatitude() const {
    return latitude;
}

double GPS::getLongitude() const {
    return longitude;
}

void GPS::update(double lat, double lon) {
    latitude = lat;
    longitude = lon;
}