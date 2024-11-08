#include <gtest/gtest.h>
#include "Wishlist.h"
#include<sstream>

TEST(WishlistTests, AddToWishlistInsertsBookTitle) {
    Wishlist wishlist;

    // Добавляем книги в список желаемого
    wishlist.addToWishlist("The Great Gatsby");
    wishlist.addToWishlist("1984");

    // Проверяем количество книг
    EXPECT_EQ(wishlist.getBookCount(), 2);

    // Проверяем, что книги добавлены
    EXPECT_TRUE(wishlist.hasBook("The Great Gatsby"));
    EXPECT_TRUE(wishlist.hasBook("1984"));
}