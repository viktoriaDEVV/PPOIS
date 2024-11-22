#include "Payment.h"

Payment::Payment(double amt, const string& method)
        : amount(amt), paymentMethod(method) {}
double Payment::calculateTotalPayment(const Hotel& hotel, const Flight& flight, const Guide& guide, int nights,const Transportation& transport) {
        double hotelCost = hotel.calculateTotalCost(nights);
        double transportationCost = transport.price;
        double flightCost = flight.price;
        double guideCost = guide.fee;
        double fullSum = hotelCost + flightCost + guideCost + transportationCost;

        return fullSum;
    }
void Payment::displayPaymentDetails() const {
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Total Amount: $" << fixed << setprecision(2) << amount << endl;
    }