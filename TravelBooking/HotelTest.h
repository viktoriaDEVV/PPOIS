#include "Hotel.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(HotelTest, GetHotelInfoReturnsCorrectString) {
    Hotel hotel("Luxury Inn", "Paris", 200.0);
    
    string expectedInfo = "Hotel Name: Luxury Inn\n"
                                "Location: Paris\n"
                                "Price per Night: $200.000000";
    EXPECT_EQ(hotel.getHotelInfo(), expectedInfo);
}

TEST(HotelTest, CalculateTotalCostReturnsCorrectValue) {
    Hotel hotel("Luxury Inn", "Paris", 200.0);
    
    EXPECT_DOUBLE_EQ(hotel.calculateTotalCost(5), 1000.0);
}

TEST(HotelTest, CalculateTotalCostWithZeroNights) {
    Hotel hotel("Luxury Inn", "Paris", 200.0);
    
    EXPECT_DOUBLE_EQ(hotel.calculateTotalCost(0), 0.0);

}

TEST(HotelTest, CalculateTotalCostWithNegativeNights) {
    Hotel hotel("Luxury Inn", "Paris", 200.0);
    
    ostringstream output;
    streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    double totalCost = hotel.calculateTotalCost(-3);

    cout.rdbuf(oldCoutBuffer);

    EXPECT_DOUBLE_EQ(totalCost, 0.0);
    EXPECT_EQ(output.str(), "Number of nights cannot be negative!\n");
}