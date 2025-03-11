#pragma once
#include <iostream>
#include "Client.h"

using namespace std;

class Rating {
public:
    Client client;
    double rating;

    Rating(const Client& clientInfo, double ratingValue);
    void validateRating();
    void displayRatingDetails() const;
    int getValue() const;
};