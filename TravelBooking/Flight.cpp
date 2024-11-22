#include "Flight.h"

string Flight::getFlightInfo() const {
        return "Flight Number: " + flightNumber + "\n" +
               "Departure: " + departure + "\n" +
               "Arrival: " + arrival + "\n" +
               "Price: $" + to_string(price);
    }
Flight::Flight(const string& flightNum, const string& flightDeparture, const string& flightArrival, double flightPrice)
        : flightNumber(flightNum), departure(flightDeparture), arrival(flightArrival), price(flightPrice) {}