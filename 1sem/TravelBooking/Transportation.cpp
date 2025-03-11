#include "Transportation.h"

    Transportation::Transportation(const string& type, double price): type(type), price(price){};

void Transportation::validatePrice() {
        if (price < 0) {
            cout << "Invalid price! Price cannot be negative." << endl;
            price = 0; // Default to 0 if invalid
        }
    }

    void Transportation::displayDetails() const {
        cout << "Transportation Type: " << type << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
    }