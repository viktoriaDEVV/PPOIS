#include "Provider.h"


    Provider::Provider(const string& providerName, const string& providerPhoneNumber, const string& providerAddress)
        : name(providerName), number(providerPhoneNumber), address(providerAddress){}

    string Provider::getName() const {
        return name;
    }

    string Provider::getPhoneNumber() const {
        return number;
    }

    string Provider::getAddress() const {
    return address;
}
    void Provider::printProviderDetails() const {
        cout << "Provider Name: " << name << "\n";
        cout << "Phone Number: " << number << "\n";
        cout << "Address: " << address << "\n";
    }