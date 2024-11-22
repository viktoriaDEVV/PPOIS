#include "Destination.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(DestinationTest, GetSummaryReturnsCorrectFormat) {
    Destination destination("France", "The city of lights");
    string summary = destination.getSummary();
    EXPECT_EQ(summary, "France: The city of lights");
}