#pragma once
#include <iostream>

using namespace std;

class Destination {
public:
    string country;
    string description;

    Destination( const string& country, const string& description);
    string getSummary() const;
};