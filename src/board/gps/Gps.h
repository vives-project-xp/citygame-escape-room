#pragma once

#include "mbed.h"
#include "MBed_Adafruit_GPS.h"

const double metersPerDegLong = 69873;
const double metersPerDegLat = 111252;

class Gps : public Adafruit_GPS
{
    public:
    Gps(Serial* serial);
    ~Gps();
    void debug(Serial* pc);
    void run();

    double latitude_in_degrees();
    double longitude_in_degrees();
    double distance_to_target(double latitudeTarget, double longitudeTarget);
    
    protected:
    static double convertDegMinToDecDeg (float degMin);
};

