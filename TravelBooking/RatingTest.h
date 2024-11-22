#include "Rating.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(RatingTest, DisplayRatingDetailsOutputsCorrectInfo) {
    Client client("John Doe", 30, "123-456-7890");
    Rating rating(client, 4.5);
    ostringstream output;  
    rating.displayRatingDetails();
    
    string expectedOutput = "Client Name: John Doe\nClient Age: 30\nClient Phone number: 123-456-7890\nRating: 4.5\n";
    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(RatingTest, ValidateRatingSetsToZeroAndOutputsErrorMessage) {
    ostringstream output;
    streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
    Client client{"John Doe", 24, "1234567890"};
    Rating rating(client, -1);

    cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(output.str(), "Invalid rating! Rating must be between 0 and 5.\n");
    
    EXPECT_EQ(rating.rating, 0);
}
