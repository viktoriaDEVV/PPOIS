#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Reader
{
public:
    string name;
    string number;
    string email;
    vector<string> borrowedBooks;

    void registerReader(const string& readerName, const string& readerNumber, const string& readerEmail);
    void updateEmail(const string& newEmail);
    void updateNumber(const string& newNumber);
    void printReaderDetails() const;
    void borrowBook(const string& bookTitle);
    void returnBook(const string& bookTitle);
    void printBorrowedBooks() const;

};