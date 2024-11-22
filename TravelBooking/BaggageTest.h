#include "Baggage.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(BaggageTest, ConstructorInitializesMembers) {
    Baggage baggage("BAG123", 10.0, 2, "USER456");

    EXPECT_EQ(baggage.baggageId, "BAG123");
    EXPECT_DOUBLE_EQ(baggage.weight, 10.0);
    EXPECT_EQ(baggage.quantity, 2);
    EXPECT_EQ(baggage.userId, "USER456");
}

TEST(BaggageTest, GetTotalWeight) {
    Baggage baggage("BAG123", 10.0, 3, "USER456");

    EXPECT_DOUBLE_EQ(baggage.getTotalWeight(), 30.0); 
}

TEST(BaggageTest, ExceedsWeightLimitFalse) {
    Baggage baggage("BAG123", 5.0, 2, "USER456");
    double weightLimit = 20.0;

    EXPECT_FALSE(baggage.exceedsWeightLimit(weightLimit)); 
}

TEST(BaggageTest, ExceedsWeightLimitTrue) {
    Baggage baggage("BAG123", 12.0, 3, "USER456");
    double weightLimit = 30.0;

    EXPECT_TRUE(baggage.exceedsWeightLimit(weightLimit));
}