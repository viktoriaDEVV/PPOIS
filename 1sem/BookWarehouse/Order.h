#pragma once
#include "Reader.h"
#include "Book.h"
#include "Date.h"
#include <vector>
#include <iostream>

using namespace std;

class Order
{
private:
    string orderNumber;
    string orderStatus;
    vector<Book> orderedBooks;
    Reader reader;
    Date orderDate;
public:

    Order(const string& number, const Reader& r, const Date& date);
    Reader getReader() const;
    Date getOrderDate() const;
    const vector<Book>& getOrderedBooks() const;
    void setOrderStatus(const string& status);
    void addBook(const Book& book);
    string getOrderStatus() const;
    void updateOrderStatus(const string& status);
    string getOrderNumber() const;
    void printOrderDetails() const;
};