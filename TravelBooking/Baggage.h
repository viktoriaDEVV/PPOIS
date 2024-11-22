#pragma once
#include <iostream>

using namespace std;

class Baggage {
public:
    string baggageId;
    double weight;
    int quantity;
    string userId;

    Baggage(const string& baggageId, double weight, int quantity, const string& userId);
    double getTotalWeight() const;
    bool exceedsWeightLimit(double weightLimit) const;
};

