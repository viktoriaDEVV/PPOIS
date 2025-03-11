#include "Baggage.h"    

    Baggage::Baggage(const string& baggageId, double weight, int quantity, const string& userId)
        : baggageId(baggageId), weight(weight), quantity(quantity), userId(userId) {}

    double Baggage::getTotalWeight() const {
        return weight * quantity;
    }

    bool Baggage::exceedsWeightLimit(double weightLimit) const {
        return getTotalWeight() > weightLimit;
    }