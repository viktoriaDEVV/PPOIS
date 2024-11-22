#pragma once
#include <iostream>

using namespace std;

class Hotel {
public:
    string name;
    string location;
    double pricePerNight;

    Hotel(const string& name, const string& location, double pricePerNight);
    string getHotelInfo() const;
    double calculateTotalCost(int nights) const;
};