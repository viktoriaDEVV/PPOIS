#include <gtest/gtest.h>
#include "Review.h"
#include<sstream>

TEST(ReviewTest, ConstructorInitializesMembers) {
    Client clientInfo{"John Doe", 24, "1234567890"};
    Destination destinationInfo{"Paris", "Eiffel Tower"};
    Rating ratingValue{clientInfo, 5};
    string reviewComment{"Amazing experience!"};

    Review review(clientInfo, destinationInfo, ratingValue, reviewComment);

    EXPECT_EQ(review.client.getName(), "John Doe");
    EXPECT_EQ(review.destination.country, "Paris");
    EXPECT_EQ(review.rating.getValue(), 5);
    EXPECT_EQ(review.comment, "Amazing experience!");
}

TEST(ReviewTest, UpdateCommentChangesComment) {
    Client clientInfo{"John Doe", 24, "1234567890"};
    Destination destinationInfo{"Paris", "Eiffel Tower"};
    Rating ratingValue{clientInfo, 5};
    string reviewComment{"Amazing experience!"};

    Review review(clientInfo, destinationInfo, ratingValue, reviewComment);
    review.updateComment("Wonderful time!");

    EXPECT_EQ(review.comment, "Wonderful time!");
}