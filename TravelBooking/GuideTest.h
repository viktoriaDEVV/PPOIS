#include "Guide.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(GuideTest, ConstructorInitializesFieldsCorrectly) {
    Guide guide("Alice Smith", "English", 150.0);
    
    EXPECT_EQ(guide.name, "Alice Smith");
    EXPECT_EQ(guide.language, "English");
    EXPECT_EQ(guide.fee, 150.0);
}

TEST(GuideTest, GetGuideInfoReturnsCorrectString) {
    Guide guide("Alice Smith", "English", 150.0);
    
    string expectedInfo = "Guide Name: Alice Smith\n"
                                "Language: English\n"
                                "Fee: $150.00000";
    EXPECT_EQ(guide.getGuideInfo(), expectedInfo);
}