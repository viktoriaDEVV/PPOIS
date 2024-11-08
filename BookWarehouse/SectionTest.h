#include <gtest/gtest.h>
#include "Section.h"
#include<sstream>

TEST(SectionTests, AddBooksIncreasesAmount) {
    Section section("Fiction", 5);

    section.addBooks(3);
    EXPECT_EQ(section.getAmountBook(), 8);

    section.addBooks(2);
    EXPECT_EQ(section.getAmountBook(), 10);
}

TEST(SectionTests, GetNameReturnsCorrectName) {
    Section section("Non-Fiction", 10);
    EXPECT_EQ(section.getName(), "Non-Fiction");
}

TEST(SectionTests, InitialAmountIsSetCorrectly) {
    Section section("Science", 15);
    EXPECT_EQ(section.getAmountBook(), 15);
}