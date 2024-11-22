#include "Wishlist.h"


    Wishlist::Wishlist(const Client& client, const vector<Destination>& destinations,
             const vector<Hotel>& hotels, const vector<Flight>& flights)
        : client(client), desiredDestinations(destinations), desiredHotels(hotels), desiredFlights(flights){}

void Wishlist::addDestination(const Destination& destination) {
        desiredDestinations.push_back(destination);
    }

    void Wishlist::removeDestination(const Destination& destination) {
        auto it = remove_if(desiredDestinations.begin(), desiredDestinations.end(),
            [&](const Destination& d) { return d.country== destination.country && d.country == destination.country; });
        desiredDestinations.erase(it, desiredDestinations.end());
    }

    void Wishlist::addHotel(const Hotel& hotel) {
        desiredHotels.push_back(hotel);
    }

    void Wishlist::removeHotel(const Hotel& hotel) {
        auto it = remove_if(desiredHotels.begin(), desiredHotels.end(),
            [&](const Hotel& h) { return h.name == hotel.name; });
        desiredHotels.erase(it, desiredHotels.end());
    }

    void Wishlist::addFlight(const Flight& flight) {
        desiredFlights.push_back(flight);
    }

    void Wishlist::removeFlight(const Flight& flight) {
        auto it = remove_if(desiredFlights.begin(), desiredFlights.end(),
            [&](const Flight& f) { return f.flightNumber == flight.flightNumber; });
        desiredFlights.erase(it, desiredFlights.end());
    }