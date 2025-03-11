#include "Reader.h"

void Reader::registerReader(const string& readerName, const string& readerNumber, const string& readerEmail) 
{
        name = readerName;
        number = readerNumber;
        email = readerEmail;
        cout << "Reader " << name << " registered successfully.\n";
}

void Reader::updateEmail(const string& newEmail) {
        email = newEmail;
        cout << "Email updated to " << email << ".\n";
    }

void Reader::updateNumber(const string& newNumber) {
        number = newNumber;
        cout << "Number updated to " << number << ".\n";
    }

void Reader::printReaderDetails() const {
        cout << "Name: " << name << "\n";
        cout << "Number: " << number << "\n";
        cout << "Email: " << email << "\n";
    }

void Reader::borrowBook(const string& bookTitle) {
        borrowedBooks.push_back(bookTitle);
        cout << bookTitle << " borrowed.\n";
    }

void Reader::returnBook(const string& bookTitle) {
        auto it = remove(borrowedBooks.begin(), borrowedBooks.end(), bookTitle);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it, borrowedBooks.end());
            cout << bookTitle << " returned.\n";
        } else {
            cout << bookTitle << " was not found in borrowed books.\n";
        }
    }

void Reader::printBorrowedBooks() const 
{
    cout << "Borrowed Books:\n";
    for (const auto& book : borrowedBooks) {
        cout << " - " << book << "\n";
    }
}