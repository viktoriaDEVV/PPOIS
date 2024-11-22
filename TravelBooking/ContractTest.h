#include "Contract.h"
#include <gtest/gtest.h>
#include<sstream>

TEST(ContractTest, ConstructorInitializesMembers) {
    Client client("Alice", 30, "123-456-7890");
    TravelAgent agent("Best Travel", "info@besttravel.com");
    Contract contract("CONTRACT123", client, agent, "2024-01-01", "2024-12-31", 1000.0);

    EXPECT_EQ(contract.contractId, "CONTRACT123");
    EXPECT_EQ(contract.client.getName(), "Alice");
    EXPECT_EQ(contract.client.getAge(), 30);
    EXPECT_EQ(contract.client.getPhoneNumber(), "123-456-7890");
    EXPECT_EQ(contract.agent.getName(), "Best Travel");
    EXPECT_EQ(contract.agent.getContactInfo(), "info@besttravel.com");
    EXPECT_EQ(contract.startDate, "2024-01-01");
    EXPECT_EQ(contract.endDate, "2024-12-31");
    EXPECT_DOUBLE_EQ(contract.totalAmount, 1000.0);
    EXPECT_FALSE(contract.isSigned);
}

TEST(ContractTest, SignContract) {
    Client client("Alice", 30, "123-456-7890");
    TravelAgent agent("Best Travel", "info@besttravel.com");
    Contract contract("CONTRACT123", client, agent, "2024-01-01", "2024-12-31", 1000.0);

    contract.signContract();

    EXPECT_TRUE(contract.isSigned);
}

TEST(ContractTest, DisplayContractDetails) {
    Client client("Alice", 30, "123-456-7890");
    TravelAgent agent("Best Travel", "info@besttravel.com");
    Contract contract("CONTRACT123", client, agent, "2024-01-01", "2024-12-31", 1000.0);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    contract.displayContractDetails();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Contract ID: CONTRACT123\n"
        "Client Name: Alice\n"
        "Client Age: 30\n"
        "Client Phone: 123-456-7890\n"
        "Travel Agent: Best Travel (info@besttravel.com)\n"
        "Start Date: 2024-01-01\n"
        "End Date: 2024-12-31\n"
        "Total Amount: $1000.00\n"
        "Is Signed: No\n";

    EXPECT_EQ(output.str(), expectedOutput);
}