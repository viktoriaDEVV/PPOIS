#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Transportation {
public:
    string type; // e.g., car, bus, train
    double price;

    Transportation(const string& type, double price);
    void validatePrice();
    void displayDetails() const;
};