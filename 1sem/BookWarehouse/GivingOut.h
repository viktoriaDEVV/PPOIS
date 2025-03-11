#pragma once
#include <iostream>
#include "Date.h"
#include "Reader.h"
#include "Book.h"

using namespace std;

class GivingOut
{
private:
    Date givingOutDate;
    Reader reader;
public:

    vector<Book> givingOutBooks;

    GivingOut(const Date& outDate, const Reader& r);
    Date getGivingOutDate() const;
    Reader getReader() const;
    void addBook(const Book& book);
    void setGivingBackDate(const Date& outDate);
    void printGivingOutDetails() const;
};