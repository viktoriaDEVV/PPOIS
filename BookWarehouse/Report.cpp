#include "Report.h"

Report::Report(const Date& date) : reportDate(date) {}

    void Report::MakeReport(const GivingOut& givingOut, const GivingBack& givingBack) {
        cout << "Report Date: " << reportDate.day << "-" << reportDate.month << "-" << reportDate.year << "\n";

        cout << "\nBooks Given Out (" << givingOut.givingOutBooks.size() << "):\n";
        for (const auto& book : givingOut.givingOutBooks) {
            cout << " - " << book.title << " by " << book.author << "\n";
        }

        cout << "\nBooks Given Back (" << givingBack.givingBackBooks.size() << "):\n";
        for (const auto& book : givingBack.givingBackBooks) {
            cout << " - " << book.title << " by " << book.author << "\n";
        }
    }