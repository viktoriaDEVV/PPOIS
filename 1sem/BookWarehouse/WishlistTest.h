#include <gtest/gtest.h>
#include "Wishlist.h"
#include<sstream>

TEST(WishlistTests, AddToWishlistInsertsBookTitle) {
    Wishlist wishlist;

    wishlist.addToWishlist("The Great Gatsby");
    wishlist.addToWishlist("1984");

    EXPECT_EQ(wishlist.getBookCount(), 2);

    EXPECT_TRUE(wishlist.hasBook("The Great Gatsby"));
    EXPECT_TRUE(wishlist.hasBook("1984"));
}