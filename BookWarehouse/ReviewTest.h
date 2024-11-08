#include <gtest/gtest.h>
#include "Review.h"
#include<sstream>

TEST(ReviewTests, ConstructorInitializesFieldsCorrectly) {
    Book book("The Great Gatsby", "F. Scott Fitzgerald", 1984, "Detective");
    Review review(book, "Alice", 5);

    EXPECT_EQ(review.getBook().title, "The Great Gatsby");
    EXPECT_EQ(review.getReviewerName(), "Alice");
    EXPECT_EQ(review.getRating(), 5);
}

TEST(ReviewTests, RatingIsValid) {
    Book book("The Great Gatsby", "F. Scott Fitzgerald", 1984, "Detective");
    Review review(book, "Bob", 4);

    EXPECT_GE(review.getRating(), 1);
    EXPECT_LE(review.getRating(), 5);
}

TEST(ReviewTests, ReviewerNameIsCorrect) {
    Book book("To Kill a Mockingbird", "Harper Lee", 1984, "Detective");
    Review review(book, "Charlie", 3);

    EXPECT_EQ(review.getReviewerName(), "Charlie");
}