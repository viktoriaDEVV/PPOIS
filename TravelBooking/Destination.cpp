#include "Destination.h"

Destination::Destination( const string& country, const string& description)
        : country(country), description(description) {}

string Destination::getSummary() const {
        return country + ": " + description;
    }

    