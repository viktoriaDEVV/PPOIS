#pragma once
#include <iostream>
#include <iomanip>
#include "Flight.h"
#include "Hotel.h"
#include "Guide.h"
#include "Transportation.h"

using namespace std;

class Payment {
public:
    double amount;
    string paymentMethod;

    Payment(double amount, const string& paymentMethod);
    double calculateTotalPayment(const Hotel& hotel, const Flight& flight, const Guide& guide, int nights,const Transportation& transport);
    void displayPaymentDetails() const;
};