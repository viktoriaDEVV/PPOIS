#include "Flight.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(FlightTest, GetFlightInfoReturnsCorrectString) {
    Flight flight {"AA123", "New York", "Los Angeles", 300.0};
    
    string expectedInfo = "Flight Number: AA123\n"
                                "Departure: Paris\n"
                                "Arrival: Los Angeles\n"
                                "Price: $300.000000";
    EXPECT_EQ(flight.getFlightInfo(), expectedInfo);
}