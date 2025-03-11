#pragma once
#include <iostream>

using namespace std;

class Flight {
public:
    string flightNumber;
    string departure;
    string arrival;
    double price;

    Flight(const string& flightNum, const string& flightDeparture, const string& flightArrival, double flightPrice);
    string getFlightInfo() const;
};