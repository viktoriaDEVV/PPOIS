#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Client.h"
#include "Flight.h"
#include "Hotel.h"
#include "Destination.h"

using namespace std;

class Wishlist {
public:
    Client client;
    vector<Destination> desiredDestinations;
    vector<Hotel> desiredHotels;
    vector<Flight> desiredFlights;

    Wishlist(const Client& client, const vector<Destination>& destinations = {},
             const vector<Hotel>& hotels = {}, const vector<Flight>& flights = {});
    void addDestination(const Destination& destination);
    void removeDestination(const Destination& destination);
    void addHotel(const Hotel& hotel);
    void removeHotel(const Hotel& hotel);
    void addFlight(const Flight& flight);
    void removeFlight(const Flight& flight);

};