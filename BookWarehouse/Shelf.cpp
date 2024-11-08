#include "Shelf.h"


    Shelf::Shelf(int shelfNumber, const Section& sec, int shelfCapacity)
        : number(shelfNumber), section(sec), capacity(shelfCapacity) {}

    int Shelf::getNumber() const {
        return number;
    }

    Section Shelf::getSection() const {
        return section;
    }

    void Shelf::addBooksToShelf(int count) {
        if (count <= capacity - section.getAmountBook()) {
            section.addBooks(count);
        } else {
            cout << "Not enough capacity on shelf " << number << " to add " << count << " books.\n";
        }
    }

    void Shelf::printShelfDetails() const {
        cout << "Shelf Number: " << number << "\n";
        cout << "Section: " << section.getName() << "\n";
        cout << "Shelf Capacity: " << capacity << "\n";
        section.printSectionDetails();
    }


