#include <gtest/gtest.h>
#include "Book.h"
#include<sstream>


TEST(BookTest, ConstructorHandlesEmptyTitle) {
    Book emptyTitleBook("", "Author", 2020, "Genre");
    EXPECT_EQ(emptyTitleBook.title, "");
}