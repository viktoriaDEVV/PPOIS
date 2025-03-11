#pragma once
#include <iostream>
#include "Client.h"
#include "Destination.h"
#include "Rating.h"

using namespace std;

class Review {
public:
    Client client;
    Destination destination;
    Rating rating;
    string comment;

    Review(const Client& clientInfo, const Destination& destinationInfo, const Rating& ratingValue, const string& reviewComment);
    void updateComment(const string& newComment);
    void displayReviewDetails() const ;
};