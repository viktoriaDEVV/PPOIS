#include "Client.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(ClientTest, SetPhoneNumberUpdatesValue) {
    Client client{"John Doe", 24, "1234567890"};
    client.setPhoneNumber("098-765-4321");
    EXPECT_EQ(client.getPhoneNumber(), "098-765-4321");
}

TEST(ClientTest, SetPhoneNumberUpdatesValue) {
    Client client{"John Doe", 24, "1234567890"};
    client.setName("Pitter");
    EXPECT_EQ(client.getName(), "Pitter");
}

TEST(ClientTest, SetPhoneNumberUpdatesValue) {
    Client client{"John Doe", 24, "1234567890"};
    client.setAge(25);
    EXPECT_EQ(client.getPhoneNumber(), 25);
}