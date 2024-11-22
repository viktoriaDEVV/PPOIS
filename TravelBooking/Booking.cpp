#include "Booking.h"

        Booking::Booking(const Client& client, const Flight& flight, const Hotel& hotel,  const Destination& destination, const string& bookingDate)
        : client(client), flight(flight), hotel(hotel),destination(destination), bookingDate(bookingDate), isCancelled(false) {}

    void Booking::cancelBooking() {
        if (!isCancelled) {
            isCancelled = true;
            cout << "Booking has been cancelled." << endl;
        } else {
            cout << "Booking is already cancelled." << endl;
        }
    }

    void Booking::changeHotel(const Hotel& newHotel) {
        hotel = newHotel;
        cout << "Hotel has been changed to: " << hotel.name << endl;
    }

    void Booking::changeFlight(const Flight& newFlight) {
        flight = newFlight;
        cout << "Flight has been changed to: " << flight.flightNumber << endl;
    }

    bool Booking::isActive() const {
        return !isCancelled;
    }
    void Booking::displayDetails() const {
        cout << "Booking Details:" << endl;
        cout << "Client Name: " << client.getName() << endl;
        cout << "Client Phone number: " << client.getPhoneNumber() << endl;
        cout << "Flight Number: " << flight.flightNumber << endl;
        cout << "Flight Destination: " << destination.country << endl;
        cout << "Hotel Name: " << hotel.name << endl;
        cout << "Booking Date: " << bookingDate << endl;
        cout << "Cancellation Status: " << (isCancelled ? "Cancelled" : "Active") << endl;
    }