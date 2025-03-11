#pragma once
#include <iostream>
#include <vector>
#include "Client.h"
#include "Booking.h"

using namespace std;

class TravelHistory {
public:
    Client client;
    vector<Booking> bookings;

    TravelHistory(const Client& client);
    void addBooking(const Booking& booking);
    void displayTravelHistory() const;
    int getBookingCount() const;
};