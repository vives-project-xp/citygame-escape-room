#include "Gps.h"
#include "mbed.h"
//required for fmod()
#include <math.h>

Gps::Gps(Serial* serial, Log::LoggerInterface * logger) : Adafruit_GPS(serial)
{
    //gps = new Adafruit_GPS(serial); //object of Adafruit's GPS class
    set_logger(logger);
    begin(9600);  //sets baud rate for GPS communication; note this may be changed via Adafruit_GPS::sendCommand(char *)
                        //a list of GPS commands is available at http://www.adafruit.com/datasheets/PMTK_A08.pdf
    wait(1.0);
    sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); //these commands are defined in MBed_Adafruit_GPS.h; a link is provided there for command creation
    sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
    sendCommand(PGCMD_ANTENNA);
}

Gps::~Gps()
{

}

void Gps::debug(){

    logger->debug("Time: %d:%d:%d.%u", hour, minute, seconds, milliseconds);
    logger->debug("Date: %d/%d/20%d", day, month, year);
    logger->debug("Fix: %d", (int) fix);
    logger->debug("Quality: %d", (int) fixquality);
    if (fix) {
        logger->debug("Location: %5.6f%c, %5.6f%c", latitude_in_degrees(), lat, longitude_in_degrees(), lon);
        logger->debug("HDOP: %5.2f", HDOP);
        logger->debug("Speed: %5.2f knots", speed);
        logger->debug("Angle: %5.2f", angle);
        logger->debug("Altitude: %5.2f", altitude);
        logger->debug("Satellites: %d", satellites);
    }
}

void Gps::run()
{
    read();   //queries the GPS

    //check if we recieved a new message from GPS, if so, attempt to parse it,
    if ( newNMEAreceived() ) {
        //logger->notice("We have received a message from the GPS!");
        parse(lastNMEA());
    }
}

// converts lat/long from Adafruit
// degree-minute format to decimal-degrees
double Gps::convertDegMinToDecDeg (float degMin) {
  double min = 0.0;
  double decDeg = 0.0;

  //get the minutes, fmod() requires double
  min = fmod((double)degMin, 100.0);

  //rebuild coordinates in decimal degrees
  degMin = (int) ( degMin / 100 );
  decDeg = degMin + ( min / 60 );

  return decDeg;
}

double Gps::latitude_in_degrees()
{
    return convertDegMinToDecDeg(latitude);
}

double Gps::longitude_in_degrees()
{
    return convertDegMinToDecDeg(longitude);
}

double Gps::distance_to_target(double latitudeTarget, double longitudeTarget)
{
    double latVar = metersPerDegLat * (latitude_in_degrees() - latitudeTarget);
    double longVar = metersPerDegLong * (longitude_in_degrees() - longitudeTarget);
    return sqrt(pow(latVar,2.0) + pow(longVar,2.0));
}
