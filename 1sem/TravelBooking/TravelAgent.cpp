#include "TravelAgent.h"

    
    TravelAgent::TravelAgent(const string& agName, const string& contInfo)
        : agentName(agName), contactInfo(contInfo) {};

    void TravelAgent::displayDetails() const {
        cout << "Travel Agent Name: " << agentName << endl;
        cout << "Contact Info: " << contactInfo << endl;
    }
    string TravelAgent::getName() const {
        return agentName;
    }
    string TravelAgent::getContactInfo() const {
        return contactInfo;
    }
    void TravelAgent::createBooking(const Client& client, const Flight& flight, const Hotel& hotel,const Destination& destination, const string& bookingDate) {
        Booking newBooking(client, flight, hotel, destination, bookingDate);
        bookings.push_back(newBooking);
        cout << "Booking created for client: " << client.getName() << endl;
    }

    void TravelAgent::cancelBooking(int bookingIndex) {
        if (bookingIndex >= 0 && bookingIndex < bookings.size()) {
            bookings[bookingIndex].cancelBooking();
        } else {
            cerr << "Invalid booking index!" << endl;
        }
    }

    void TravelAgent::displayBookings() const {
        for (const auto& booking : bookings) {
            cout << "Client: " << booking.client.getName() 
                      << ", Flight: " << booking.flight.flightNumber 
                      << ", Hotel: " << booking.hotel.name 
                      << ", Booking Date: " << booking.bookingDate 
                      << ", Cancelled: " << (booking.isCancelled ? "Yes" : "No") << endl;
        }
    }