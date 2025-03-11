#include "TravelHistory.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(TravelHistoryTest, DisplayTravelHistoryOutputsCorrectInfo) {

    ostringstream output; 
    Client client1{"John Doe", 24, "1234567890"};
    Flight flight1{"AA123", "New York", "Los Angeles", 300.0};
    Hotel hotel1{"Grand Hotel", "Paris", 150.0};
    Destination destination1{"USA", "A great place to visit."};
    string bookingDate1{"2024-11-16"};
    Booking booking1(client1, flight1, hotel1, destination1, bookingDate1);

    Flight flight2{"AA123", "Paris", "Los Angeles", 300.0};
    Hotel hotel2{"Grand Hotel", "Paris", 450.0};
    Destination destination2{"New York", "A great place to visit."};
    string bookingDate2{"2022-11-16"};
    Booking booking2(client1, flight2, hotel2, destination2, bookingDate2);

    TravelHistory travelHistory(client1 );
    travelHistory.addBooking(booking1);
    travelHistory.addBooking(booking2);

    travelHistory.displayTravelHistory();

    string expectedOutput = "Travel History for: John Doe\n"
                                  "Booking Details:\n"
                                  "Client Name: John Doe\n"
                                  "Client Phone number: 1234567890\n"
                                  "Flight Number: AB123\n"
                                  "Flight Destination: USA\n"
                                  "Hotel Name: Grand Hotel\n"
                                  "Booking Date: 2024-11-16\n"
                                  "Cancellation Status: Active\n"
                                  "Booking Details:\n"
                                  "Client Name: John Doe\n"
                                  "Client Phone number: 1234567890\n"
                                  "Flight Number: AB123\n"
                                  "Flight Destination: New York\n"
                                  "Hotel Name: Grand Hotel\n"
                                  "Booking Date: 2022-11-16\n"
                                  "Cancellation Status: Cancelled\n";
    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(TravelHistoryTest, GetBookingCountReturnsCorrectCount) {

    Client client1{"Alice", 24, "1234567890"};
    TravelHistory travelHistory(client1 );
    EXPECT_EQ(travelHistory.getBookingCount(), 0);
    
    Flight flight2{"AA123", "Paris", "Los Angeles", 300.0};
    Hotel hotel2{"Grand Hotel", "Paris", 450.0};
    Destination destination2{"New York", "A great place to visit."};
    string bookingDate2{"2022-11-16"};
    Booking booking(client1, flight2, hotel2, destination2, bookingDate2);
    travelHistory.addBooking(booking);
    
    EXPECT_EQ(travelHistory.getBookingCount(), 1);
}