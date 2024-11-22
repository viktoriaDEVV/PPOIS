#include "Client.h"

   
    Client::Client(const string& clientName, int clientAge, const string& phNumber)
        : name(clientName), age(clientAge), phoneNumber(phNumber) {}

    string Client::getName() const {
        return name;
    }

    void Client::setName(const string& clientName) {
        name = clientName;
    }

    int Client::getAge() const {
        return age;
    }

    void Client::setAge(int clientAge) {
        age = clientAge;
    }

    string Client::getPhoneNumber() const {
        return phoneNumber;
    }

    void Client::setPhoneNumber(const string& phNumber) {
        phoneNumber = phNumber;
    }

    void Client::displayInfo() const {
        cout << "Client Name: " << name << endl;
        cout << "Client Age: " << age << endl;
        cout << "Client Phone number: " << phoneNumber << endl;
    }
    