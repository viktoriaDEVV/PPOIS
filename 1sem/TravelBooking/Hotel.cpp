#include "Hotel.h"

Hotel::Hotel(const string& hotelName, const string& hotelLocation, double price)
        : name(hotelName), location(hotelLocation), pricePerNight(price) {}
string Hotel::getHotelInfo() const {
        return "Hotel Name: " + name + "\n" +
               "Location: " + location + "\n" +
               "Price per Night: $" + to_string(pricePerNight);
    }
double Hotel::calculateTotalCost(int nights) const {
        if (nights < 0) {
            cout << "Number of nights cannot be negative!" << endl;
            return 0.0;
        }
        return pricePerNight * nights;
    }