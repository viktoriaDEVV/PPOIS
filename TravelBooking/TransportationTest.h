#include "Transportation.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(TransportationTest, ConstructorInitializesMembers) {
    Transportation transport("Bus", 20.0);
    
    EXPECT_EQ(transport.type, "Bus");      
    EXPECT_DOUBLE_EQ(transport.price, 20.0);   
}

TEST(TransportationTest, DisplayDetails) {
    Transportation transport("Taxi", 25.0);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf()); 

    transport.displayDetails(); 

    std::cout.rdbuf(oldCoutBuffer); 

    std::string expectedOutput = "Transportation Type: Taxi\nPrice: $25.00\n";
    EXPECT_EQ(output.str(), expectedOutput); 
}