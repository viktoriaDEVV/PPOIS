#include "GivingOut.h"


    GivingOut::GivingOut(const Date& outDate, const Reader& r)
        : givingOutDate(outDate), reader(r) {}


    void GivingOut::addBook(const Book& book) {
        givingOutBooks.push_back(book);
    }

    void GivingOut::setGivingBackDate(const Date& outDate) {
        givingOutDate = outDate;
    }

    void GivingOut::printGivingOutDetails() const {
        cout << "Giving Out Date: " << givingOutDate.day << "-" << givingOutDate.month << "-" << givingOutDate.year << "\n";
        cout << "Reader: " << reader.name << "\n";
        cout << "Books Given Out: \n";
        for (const auto& book : givingOutBooks) {
            cout << " - " << book.title << "\n";
        }
    }
    Date GivingOut::getGivingOutDate() const { return givingOutDate; }
    Reader GivingOut::getReader() const { return reader; }
