#include <gtest/gtest.h>
#include "Shelf.h"
#include<sstream>

TEST(ShelfTests, AddBooksToShelfIncreasesBookCount) {
    Section section("Fiction", 5);
    Shelf shelf(1, section, 10);

    shelf.addBooksToShelf(5);
    EXPECT_EQ(shelf.getSection().getAmountBook(), 5);

    shelf.addBooksToShelf(3);
    EXPECT_EQ(shelf.getSection().getAmountBook(), 8);
}

TEST(ShelfTests, AddBooksToShelfExceedsCapacity) {
    Section section("Fiction", 6);
    Shelf shelf(1, section, 10);

    shelf.addBooksToShelf(10);
    EXPECT_EQ(shelf.getSection().getAmountBook(), 10);

    shelf.addBooksToShelf(5);
    EXPECT_EQ(shelf.getSection().getAmountBook(), 10);
}

TEST(ShelfTests, GetShelfNumberReturnsCorrectNumber) {
    Section section("Fiction",8);
    Shelf shelf(1, section, 10);

    EXPECT_EQ(shelf.getNumber(), 1);
}

TEST(ShelfTests, GetSectionReturnsCorrectSection) {
    Section section("Fiction", 5);
    Shelf shelf(1, section, 10);

    EXPECT_EQ(shelf.getSection().getName(), "Fiction");
}