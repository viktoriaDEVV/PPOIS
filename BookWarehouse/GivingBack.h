#pragma once
#include <iostream>
#include "Date.h"
#include "Reader.h"
#include "Book.h"

using namespace std;

class GivingBack
{
private:
    Date givingBackDate;
    Reader reader;
    string state;
public:

    vector<Book> givingBackBooks;

    GivingBack(const Date& backDate, const Reader& r);
    string getState() const;
    void addBook(const Book& book);
    void updateState(const string& newState);
    void printGivingBackDetails() const;
};