#include <gtest/gtest.h>
#include "Order.h"
#include<sstream>


TEST(OrderTests, ConstructorInitializesFields) {
    Reader reader = {"John Doe"};
    Date orderDate = {10, 11, 2023}; // Пример: 10-11-2023
    Order order("Order001", reader, orderDate);

    EXPECT_EQ(order.getOrderNumber(), "Order001");
    EXPECT_EQ(order.getOrderStatus(), "Pending");
    EXPECT_EQ(order.getReader().name, "John Doe");
    EXPECT_EQ(order.getOrderDate().day, 10);
    EXPECT_EQ(order.getOrderDate().month, 11);
    EXPECT_EQ(order.getOrderDate().year, 2023);
}

TEST(OrderTests, AddBookIncreasesOrderedBooks) {
    Reader reader = {"John Doe"};
    Date orderDate = {10, 11, 2023};
    Order order("Order001", reader, orderDate);

    Book book1("Sun", "Author", 2020, "Genre");
    Book book2("Moon", "Author", 2022, "Genre");

    order.addBook(book1);
    order.addBook(book2);

    EXPECT_EQ(order.getOrderedBooks().size(), 2);
    EXPECT_EQ(order.getOrderedBooks()[0].title, "Sun");
    EXPECT_EQ(order.getOrderedBooks()[1].title, "Moon");
}

TEST(OrderTests, UpdateOrderStatusChangesStatus) {
    Reader reader = {"John Doe"};
    Date orderDate = {10, 11, 2023};
    Order order("Order001", reader, orderDate);

    order.setOrderStatus("Shipped");
    EXPECT_EQ(order.getOrderStatus(), "Shipped");
}

TEST(OrderTests, PrintOrderDetailsOutputsCorrectInfo) {
    Reader reader = {"John Doe"};
    Date orderDate = {10, 11, 2023};
    Order order("Order001", reader, orderDate);

    std::ostringstream buffer;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    order.printOrderDetails();

    std::cout.rdbuf(originalCoutBuffer);

    std::string expectedOutput = 
        "Order Number: Order001\n"
        "Order Status: Pending\n"
        "Reader: John Doe\n"
        "Order Date: 10-11-2023\n"
        "Ordered Books: \n";
    
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(OrderTests, InitialOrderIsPending) {
    Reader reader = {"John Doe"};
    Date orderDate = {10, 11, 2023};
    Order order("Order001", reader, orderDate);

    EXPECT_EQ(order.getOrderStatus(), "Pending");
}
