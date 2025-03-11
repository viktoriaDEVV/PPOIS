#pragma once
#include <iostream>
#include <vector>
#include "Client.h"
#include "Flight.h"
#include "Hotel.h"
#include "Destination.h"

using namespace std;

class Booking {
public:
    Client client;
    Flight flight;
    Hotel hotel;
    Destination destination;
    string bookingDate;
    bool isCancelled;

    Booking(const Client& client, const Flight& flight, const Hotel& hotel,  const Destination& destination, const string& bookingDate);
    void cancelBooking();
    void changeHotel(const Hotel& newHotel);
    void changeFlight(const Flight& newFlight);
    bool isActive() const;
    void displayDetails() const;
};