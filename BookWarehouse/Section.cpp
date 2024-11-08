#include "Section.h"


    Section::Section(const string& sectionName, int initialAmount)
        : name(sectionName), amountBook(initialAmount) {}

    string Section::getName() const {
        return name;
    }

    void Section::addBooks(int count) {
        amountBook += count;
        cout << count << " books added to section " << name << ". Total: " << amountBook << "\n";
    }

    int Section::getAmountBook() const {
        return amountBook;
    }

    void Section::printSectionDetails() const {
        cout << "Section Name: " << name << "\n";
        cout << "Amount of Books: " << amountBook << "\n";
    }
