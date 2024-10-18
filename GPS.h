#ifndef GPS_H
#define GPS_H

class GPS {
public:
    GPS();
    GPS(double latitude, double longitude);
    double getLatitude() const;
    double getLongitude() const;
    void update(double latitude, double longitude);

private:
    double latitude;
    double longitude;
};

#endif // GPS_H