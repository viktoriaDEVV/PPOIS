#include <gtest/gtest.h>
#include "Worker.h"
#include<sstream>

TEST(WorkerTests, ConstructorInitializesCorrectly) {
    Worker worker("Alice", 50000.0);
    
    EXPECT_EQ(worker.getName(), "Alice");
    EXPECT_EQ(worker.getSalary(), 50000.0);
}

TEST(WorkerTests, TakeSalaryUpdatesBudget) {
    Worker worker("Bob", 3000.0);
    double budget = 10000.0;

    worker.TakeSalary(&budget);

    EXPECT_EQ(budget, 7000.0);
}

TEST(WorkerTests, SortBooksAlphabeticallyByAuthor) {
    Worker worker("Charlie", 4000.0);
    vector<Book> books = { {"Book A", "Zebra", 1998, "Roman"}, {"Book B", "Apple", 2003, "Detective"}, {"Book C", "Mango", 2001, "Tail"} };

    worker.Sort(books);

    EXPECT_EQ(books[0].author, "Apple");
    EXPECT_EQ(books[1].author, "Mango");
    EXPECT_EQ(books[2].author, "Zebra");
}