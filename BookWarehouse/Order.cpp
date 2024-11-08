#include "Order.h"

Order::Order(const string& number, const Reader& r, const Date& date)
        : orderNumber(number), reader(r), orderDate(date), orderStatus("Pending") {}
Reader Order::getReader() const {
        return reader;
    }

    Date Order::getOrderDate() const {
        return orderDate;
    }

    const vector<Book>& Order::getOrderedBooks() const {
        return orderedBooks;
    }

    // Сеттеры
    void Order::setOrderStatus(const string& status) {
        orderStatus = status;
    }

void Order::addBook(const Book& book) {
        orderedBooks.push_back(book);
    }

string Order::getOrderStatus() const {
        return orderStatus;
    }

void Order::updateOrderStatus(const string& status) {
        orderStatus = status;
    }

string Order::getOrderNumber() const {
        return orderNumber;
    }

void Order::printOrderDetails() const {
        cout << "Order Number: " << orderNumber << "\n";
        cout << "Order Status: " << orderStatus << "\n";
        cout << "Reader: " << reader.name << "\n";
        cout << "Order Date: " << orderDate.day << "-" << orderDate.month << "-" << orderDate.year << "\n";
        cout << "Ordered Books: \n";
        for (const auto& book : orderedBooks) {
            cout << " - " << book.title << "\n";
        }
    }