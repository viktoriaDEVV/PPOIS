#include <gtest/gtest.h>
#include "Booking.h"
#include<sstream>

TEST(BookingTest, ConstructorSetsValues) {
    Client client{"John Doe", 24, "1234567890"};
    Flight flight{"AA123", "New York", "Los Angeles", 300.0};
    Hotel hotel{"Grand Hotel", "Paris", 150.0};
    Destination destination{"USA", "A great place to visit."};
    string bookingDate{"2024-11-16"};
    Booking booking(client, flight, hotel, destination, bookingDate);

    EXPECT_EQ(booking.client.getName(), "John Doe");
    EXPECT_EQ(booking.flight.flightNumber, "AA123");
    EXPECT_EQ(booking.hotel.name, "Grand Hotel");
    EXPECT_EQ(booking.destination.country, "USA");
    EXPECT_EQ(booking.bookingDate,"2024-11-16");
    EXPECT_TRUE(booking.isActive());
}

TEST(BookingTest, CancelBooking) {
    Client client{"John Doe", 24, "1234567890"};
    Flight flight{"AA123", "New York", "Los Angeles", 300.0};
    Hotel hotel{"Grand Hotel", "Paris", 150.0};
    Destination destination{"USA", "A great place to visit."}; 
    string bookingDate{"2024-11-16"};
    Booking booking(client, flight, hotel, destination, bookingDate);

    booking.cancelBooking();
    EXPECT_FALSE(booking.isActive());
}

TEST(BookingTest, CancelBookingTwice) {
    Client client{"John Doe", 24, "1234567890"};
    Flight flight{"AA123", "New York", "Los Angeles", 300.0};
    Hotel hotel{"Grand Hotel", "Paris", 150.0};
    Destination destination{"USA", "A great place to visit."}; 
    string bookingDate{"2024-11-16"};
    Booking booking(client, flight, hotel, destination, bookingDate);

    booking.cancelBooking();
    testing::internal::CaptureStdout();
    booking.cancelBooking();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Booking is already cancelled.\n");
}

TEST(BookingTest, ChangeHotel) {
    Client client{"John Doe", 24, "1234567890"};
    Flight flight{"AA123", "New York", "Los Angeles", 300.0};
    Hotel hotel{"Grand Hotel", "Paris", 150.0};
    Destination destination{"USA", "A great place to visit."};
    string bookingDate{"2024-11-16"};
    Booking booking(client, flight, hotel, destination, bookingDate);

    Hotel newHotel{"Luxury Hotel", "London", 450.0};
    booking.changeHotel(newHotel);
    EXPECT_EQ(booking.hotel.name, "Luxury Hotel");
}

TEST(BookingTest, ChangeFlight) {
    Client client{"John Doe", 24, "1234567890"};
    Flight flight{"AA123", "New York", "Los Angeles", 300.0};
    Hotel hotel{"Grand Hotel", "Paris", 150.0};
    string bookingDate{"2024-11-16"};
    Destination destination{"USA", "A great place to visit."};
    Booking booking(client, flight, hotel, destination, bookingDate);

    Flight newFlight{"BB456", "Texas", "Koner", 400.0};
    booking.changeFlight(newFlight);
    EXPECT_EQ(booking.flight.flightNumber, "BB456");
}

TEST(BookingTest, DisplayDetails) {
    Client client{"John Doe", 24, "1234567890"};
    Flight flight{"AA123", "New York", "Los Angeles", 300.0};
    Hotel hotel{"Grand Hotel", "Paris", 150.0};
    string bookingDate{"2024-11-16"};
    Destination destination{"USA", "A great place to visit."};
    Booking booking(client, flight, hotel, destination, bookingDate);

    testing::internal::CaptureStdout();
    booking.displayDetails();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Client Name: John Doe") != string::npos);
    EXPECT_TRUE(output.find("Flight Number: AA123") != string::npos);
    EXPECT_TRUE(output.find("Hotel Name: Grand Hotel") != string::npos);
    EXPECT_TRUE(output.find("Cancellation Status: Active") != string::npos);
}

