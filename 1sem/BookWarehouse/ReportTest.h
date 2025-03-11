#include <gtest/gtest.h>
#include "Report.h"
#include "GivingOut.h"
#include "GivingBack.h"
#include<sstream>

TEST(ReportTests, MakeReportHandlesMultipleBooks) {

    Date date1 = {10, 11, 2023};
    Date date2 = {15, 11, 2023};
    Reader reader1 = {"Alice", "12345", "alice@example.com"};
    GivingOut givingOut(date1, reader1);
    Report report(date2);
    GivingBack givingBack(date2, reader1);

    givingOut.addBook(Book("1984", "George Orwell", 2001, "Mistics"));
    givingOut.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1999, "Roman"));
    givingBack.addBook(Book("1999", "George Orwell", 2005, "Detective"));

    EXPECT_NO_THROW(report.MakeReport(givingOut, givingBack));
}

TEST(ReportTests, MakeReportHandlesEmptyLists) {
 
    Date date1 = {10, 11, 2023};
    Date date2 = {15, 11, 2023};
    Reader reader1 = {"Alice", "12345", "alice@example.com"};
    GivingOut givingOut(date1, reader1);
    Report report(date2);
    GivingBack givingBack(date2, reader1); 

    EXPECT_NO_THROW(report.MakeReport(givingOut, givingBack));
}
