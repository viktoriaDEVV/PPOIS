#include <gtest/gtest.h>
#include "Warehouse.h"
#include<sstream>

TEST(WarehouseTests, AddBooksIncreasesBookCount) {
    Warehouse warehouse(100, "Main St", 5000.0);

    warehouse.addBooks(10);
    EXPECT_EQ(warehouse.getAmountBook(), 10);

    warehouse.addBooks(5);
    EXPECT_EQ(warehouse.getAmountBook(), 15);
}

TEST(WarehouseTests, RemoveBooksIncreasesBookCount) {
    Warehouse warehouse(100, "Main St", 5000.0);

    warehouse.removeBooks(10);
    EXPECT_EQ(warehouse.getAmountBook(), 10);

    warehouse.removeBooks(5);
    EXPECT_EQ(warehouse.getAmountBook(), 15);
}

TEST(WarehouseTests, UpdateBudgetIncreasesBudget) {
    Warehouse warehouse(100, "Main St", 5000.0);

    warehouse.updateBudget(1500.0);
    EXPECT_EQ(warehouse.getBudget(), 6500.0);

    warehouse.updateBudget(-2000.0);
    EXPECT_EQ(warehouse.getBudget(), 4500.0);
}

TEST(WarehouseTests, ConstructorInitializesFieldsCorrectly) {
    Warehouse warehouse(100, "Main St", 5000.0);

    EXPECT_EQ(warehouse.getArea(), 100);
    EXPECT_EQ(warehouse.getStreet(), "Main St");
    EXPECT_EQ(warehouse.getBudget(), 5000.0);
    EXPECT_EQ(warehouse.getAmountBook(), 0);
}