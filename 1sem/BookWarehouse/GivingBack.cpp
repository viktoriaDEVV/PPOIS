#include "GivingBack.h"


    GivingBack::GivingBack(const Date& backDate, const Reader& r)
        : givingBackDate(backDate), reader(r), state("completed") {}

    void GivingBack::addBook(const Book& book) {
        givingBackBooks.push_back(book);
    }

    void GivingBack::updateState(const string& newState) {
        state = newState;
    }

    void GivingBack::printGivingBackDetails() const {
        cout << "Giving Back Date: " << givingBackDate.day << "-" << givingBackDate.month << "-" << givingBackDate.year << "\n";
        cout << "Reader: " << reader.name << "\n";
        cout << "Books Given Back: \n";
        for (const auto& book : givingBackBooks) {
            cout << " - " << book.title << "\n";
        }
        cout << "State: " << state << "\n";
    }

    string GivingBack::getState() const { return state; }
