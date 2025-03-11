#pragma once
#include <iostream>

using namespace std;

class Provider
{
private:
    string name;
    string number;
    string address;
public:

    Provider(const string& providerName, const string& providerPhoneNumber, const string& providerAddress);
    string getAddress() const;
    string getName() const;
    string getPhoneNumber() const;
    void printProviderDetails() const;
};