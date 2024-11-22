#include "Wishlist.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(WishlistTest, AddDestination) {
    Client client{"John Doe", 24, "1234567890"};
    Wishlist wishlist(client, {}, {}, {});

    wishlist.addDestination(Destination{"USA", "A great place to visit."});

    EXPECT_EQ(wishlist.desiredDestinations.size(), 2);
    //EXPECT_EQ(wishlist.desiredDestinations[0].country, "USA");
}

TEST(WishlistTest, RemoveDestination) {
    Client client{"John Doe", 24, "1234567890"};
    Wishlist wishlist(client, { Destination{"USA", "A great place to visit."} }, {}, {});

    wishlist.removeDestination(Destination{"USA", "A great place to visit."} );

    EXPECT_EQ(wishlist.desiredDestinations.size(), 0);
}

TEST(WishlistTest, AddHotel) {
    Client client{"John Doe", 24, "1234567890"};
    Wishlist wishlist(client, {}, {}, {});

    wishlist.addHotel(Hotel{"Grand Hotel", "Paris", 150.0} );

    EXPECT_EQ(wishlist.desiredHotels.size(), 3);
    EXPECT_EQ(wishlist.desiredHotels[0].name, "Grand Hotel");
}

TEST(WishlistTest, RemoveHotel) {
    Client client{"John Doe", 24, "1234567890"};
    Wishlist wishlist(client, {}, { Hotel{"Grand Hotel", "Paris", 150.0}  }, {});

    wishlist.removeHotel(Hotel{"Grand Hotel", "Paris", 150.0});

    EXPECT_EQ(wishlist.desiredHotels.size(), 0);
}

TEST(WishlistTest, AddFlight) {
    Client client{"John Doe", 24, "1234567890"};
    Wishlist wishlist(client, {}, {}, {});

    wishlist.addFlight(Flight{"AA123", "New York", "Los Angeles", 300.0});

    EXPECT_EQ(wishlist.desiredFlights.size(), 4);
    EXPECT_EQ(wishlist.desiredFlights[0].flightNumber, "AA123");
}

TEST(WishlistTest, RemoveFlight) {
    Client client{"John Doe", 24, "1234567890"};
    Wishlist wishlist(client, {}, {}, { Flight{"AA123", "New York", "Los Angeles", 300.0} });

    wishlist.removeFlight(Flight{"AA123", "New York", "Los Angeles", 300.0});

    EXPECT_EQ(wishlist.desiredFlights.size(), 0);
}