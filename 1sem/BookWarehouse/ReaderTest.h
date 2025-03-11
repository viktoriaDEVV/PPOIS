#include <gtest/gtest.h>
#include "Order.h"
#include<sstream>

TEST(ReaderTests, RegisterReaderStoresInformation) {
    Reader reader;
    reader.registerReader("Alice", "12345", "alice@example.com");

    EXPECT_EQ(reader.name, "Alice");
    EXPECT_EQ(reader.number, "12345");
    EXPECT_EQ(reader.email, "alice@example.com");
}

TEST(ReaderTests, UpdateEmailChangesEmail) {
    Reader reader;
    reader.registerReader("Alice", "12345", "alice@example.com");

    reader.updateEmail("alice.new@example.com");
    EXPECT_EQ(reader.email, "alice.new@example.com");
}

TEST(ReaderTests, UpdateNumberChangesNumber) {
    Reader reader;
    reader.registerReader("Alice", "12345", "alice@example.com");

    reader.updateNumber("67890");
    EXPECT_EQ(reader.number, "67890");
}

TEST(ReaderTests, BorrowBookAddsToList) {
    Reader reader;
    reader.borrowBook("The Great Gatsby");

    EXPECT_EQ(reader.borrowedBooks.size(), 1);
    EXPECT_EQ(reader.borrowedBooks[0], "The Great Gatsby");
}

TEST(ReaderTests, ReturnBookRemovesFromList) {
    Reader reader;
    reader.borrowBook("1984");
    reader.borrowBook("The Great Gatsby");

    reader.returnBook("1984");
    EXPECT_EQ(reader.borrowedBooks.size(), 1);
    EXPECT_EQ(reader.borrowedBooks[0], "The Great Gatsby");
}

TEST(ReaderTests, ReturnBookNotInList) {
    Reader reader;
    reader.borrowBook("The Great Gatsby");

    reader.returnBook("1984");
    EXPECT_EQ(reader.borrowedBooks.size(), 1);
    EXPECT_EQ(reader.borrowedBooks[0], "The Great Gatsby");
}