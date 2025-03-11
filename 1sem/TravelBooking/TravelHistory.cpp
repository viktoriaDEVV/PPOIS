#include"TravelHistory.h"

TravelHistory::TravelHistory(const Client& client) : client(client) {}

void TravelHistory::addBooking(const Booking& booking) {
    bookings.push_back(booking);
}

void TravelHistory::displayTravelHistory() const {
    cout << "Travel History for: " << client.getName() << endl;
    for (const auto& booking : bookings) {
        booking.displayDetails();
    }
}

int TravelHistory::getBookingCount() const {
    return bookings.size();
}