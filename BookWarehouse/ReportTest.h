#include <gtest/gtest.h>
#include "Report.h"
#include "GivingOut.h"
#include "GivingBack.h"
#include<sstream>

/*TEST(ReportTests, MakeReportOutputsCorrectInformation) {
    // Создание даты отчета
    Date reportDate = {10, 11, 2023};
    Report report(reportDate);

    // Создание выданных книг
    Date date1 = {10, 11, 2023};
    Reader reader1 = {"Alice", "12345", "alice@example.com"};
    GivingOut givingOut(date1, reader1);
    givingOut.givingOutBooks.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", 1984, "Detective"));
    givingOut.givingOutBooks.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", 1984, "Detective"));

    // Создание возвращённых книг
    Date date2 = {15, 11, 2023};
    Reader reader2 = {"Ana", "12345", "alice@example.com"};
    GivingBack givingBack(date2, reader2);
    givingBack.givingBackBooks.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1984, "Detective"));

    // Проверяем, что информация о выданных и возвращённых книгах правильная
    EXPECT_EQ(givingOut.givingOutBooks.size(), 2);
    EXPECT_EQ(givingBack.givingBackBooks.size(), 1);

    // Проверяем содержимое выданных книг
    EXPECT_EQ(givingOut.givingOutBooks[0].title, "The Great Gatsby");
    EXPECT_EQ(givingOut.givingOutBooks[0].author, "F. Scott Fitzgerald");
    EXPECT_EQ(givingOut.givingOutBooks[1].publicationYear, "1984");
    EXPECT_EQ(givingOut.givingOutBooks[1].genre, "Detective");

    // Проверяем содержимое возвращённых книг
    EXPECT_EQ(givingBack.givingBackBooks[0].title, "To Kill a Mockingbird");
    EXPECT_EQ(givingBack.givingBackBooks[0].author, "Harper Lee");
}*/

/*TEST(ReportTests, MakeReportOutputsCorrectInformation) {
    Date date1 = {10, 11, 2023};
    Date date2 = {15, 11, 2023};
    Reader reader1 = {"Alice", "12345", "alice@example.com"};
    GivingOut givingOut(date1, reader1);
    Report report(date2);
    GivingBack givingBack(date2, reader1);

    // Добавляем книги в выданные и возвращенные
    givingOut.addBook(Book("1984", "George Orwell", 2001, "Mistics"));
    givingOut.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1999, "Roman"));
    givingBack.addBook(Book("1999", "George Orwell", 2005, "Detective"));

    // Генерируем отчет
    void output = report.MakeReport(givingOut, givingBack);

    // Ожидаемое значение отчета
    void expectedOutput = 
        "Report Date: 15-11-2023\n"
        "\nBooks Given Out (2):\n"
        " - 1984 by George Orwell\n"
        " - To Kill a Mockingbird by Harper Lee\n"
        "\nBooks Given Back (1):\n"
        " - 1984 by George Orwell\n";

    // Сравниваем с ожидаемым значением
    EXPECT_EQ(output, expectedOutput);
}*/

TEST(ReportTests, MakeReportHandlesMultipleBooks) {
    // Установка даты отчета
    Date date1 = {10, 11, 2023};
    Date date2 = {15, 11, 2023};
    Reader reader1 = {"Alice", "12345", "alice@example.com"};
    GivingOut givingOut(date1, reader1);
    Report report(date2);
    GivingBack givingBack(date2, reader1);

    // Добавление книг
    givingOut.addBook(Book("1984", "George Orwell", 2001, "Mistics"));
    givingOut.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1999, "Roman"));
    givingBack.addBook(Book("1999", "George Orwell", 2005, "Detective"));

    // Проверяем, что метод не вызывает исключения
    EXPECT_NO_THROW(report.MakeReport(givingOut, givingBack));
}

TEST(ReportTests, MakeReportHandlesEmptyLists) {
    // Установка даты отчета
    Date date1 = {10, 11, 2023};
    Date date2 = {15, 11, 2023};
    Reader reader1 = {"Alice", "12345", "alice@example.com"};
    GivingOut givingOut(date1, reader1);
    Report report(date2);
    GivingBack givingBack(date2, reader1); // Пустой список возвращенных книг

    // Проверяем, что метод не вызывает исключения
    EXPECT_NO_THROW(report.MakeReport(givingOut, givingBack));
}
