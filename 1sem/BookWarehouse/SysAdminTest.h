#include <gtest/gtest.h>
#include "SysAdmin.h"
#include<sstream>

TEST(SysAdminTests, GetFullNameReturnsCorrectName) {
    SysAdmin admin("John", "Doe", "jdoe", "password123");
    EXPECT_EQ(admin.getFullName(), "John Doe");
}

TEST(SysAdminTests, SetPasswordUpdatesPassword) {
    SysAdmin admin("John", "Doe", "jdoe", "password123");
    admin.setPassword("newPassword");
    EXPECT_TRUE(admin.checkPassword("newPassword"));
    EXPECT_FALSE(admin.checkPassword("password123"));
}

TEST(SysAdminTests, CheckPasswordReturnsTrueForCorrectPassword) {
    SysAdmin admin("John", "Doe", "jdoe", "password123");
    EXPECT_TRUE(admin.checkPassword("password123"));
    EXPECT_FALSE(admin.checkPassword("wrongPassword"));
}

TEST(SysAdminTests, AddUserLogsAction) {
    testing::internal::CaptureStdout(); // Захватываем вывод в стандартный поток
    SysAdmin admin("John", "Doe", "jdoe", "password123");
    admin.addUser("newUser");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("User newUser added.") != string::npos);
    EXPECT_TRUE(output.find("Log: Added user newUser performed by John Doe.") != string::npos);
}

TEST(SysAdminTests, RemoveUserLogsAction) {
    testing::internal::CaptureStdout();
    SysAdmin admin("John", "Doe", "jdoe", "password123");
    admin.removeUser("oldUser");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("User oldUser removed.") != string::npos);
    EXPECT_TRUE(output.find("Log: Removed user oldUser performed by John Doe.") != string::npos);
}

TEST(SysAdminTests, ResetPasswordGeneratesDefaultPassword) {
    testing::internal::CaptureStdout();
    SysAdmin admin("John", "Doe", "jdoe", "password123");
    admin.resetPassword("userToReset");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Password for userToReset reset to defaultPassword.") != string::npos);
    EXPECT_TRUE(output.find("Log: Reset password for userToReset performed by John Doe.") != string::npos);
}

TEST(SysAdminTests, UpdateSystemSettingsLogsAction) {
    testing::internal::CaptureStdout();
    SysAdmin admin("John", "Doe", "jdoe", "password123");
    admin.updateSystemSettings("Maintenance", "Active");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("System setting Maintenance updated to Active.") != string::npos);
    EXPECT_TRUE(output.find("Log: Updated system setting Maintenance performed by John Doe.") != string::npos);
}

TEST(SysAdminTests, GenerateSystemReportWorks) {
    testing::internal::CaptureStdout();
    SysAdmin admin("John", "Doe", "jdoe", "password123");
    admin.generateSystemReport();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Generating system report...") != string::npos);
}