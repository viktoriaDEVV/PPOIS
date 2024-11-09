#include <gtest/gtest.h>
#include "Date.h"
#include<sstream>

TEST(DateTest, DisplayOutputsCorrectFormat) {
    Date* date;
    date = new Date(10, 11, 2023);
    std::ostringstream buffer;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(buffer.rdbuf());
    
    date->Display();
    
    std::cout.rdbuf(originalCoutBuffer);

    EXPECT_EQ(buffer.str(), "10/11/2023");
}