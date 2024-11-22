#pragma once
#include <iostream>
#include "Booking.h"
#include "Client.h"
#include "Flight.h"
#include "Hotel.h"
#include "Destination.h"

using namespace std;

class TravelAgent
{
private:
    string agentName;
    string contactInfo;
    vector<Booking> bookings;

public:
    TravelAgent(const string& agName, const string& contInfo );
    void displayDetails() const;
    string getName() const;
    string getContactInfo() const;
    void createBooking(const Client& client, const Flight& flight, const Hotel& hotel, const Destination& destination, const string& bookingDate);
    void cancelBooking(int bookingIndex);
    void displayBookings() const;
};