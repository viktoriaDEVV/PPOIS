#pragma once
#include <iostream>
//#include "Contract.h"

using namespace std;

class Client
{
private:
    string name;
    int age;
    string phoneNumber;
public:
    Client(const string& clientName, int clientAge, const string& phNumber );
    string getName() const;
    void setName(const string& clientName);
    int getAge() const;
    void setAge(int clientAge);
    string getPhoneNumber() const;
    void setPhoneNumber(const string& phNumber);
    //void signContract(Contract& contract);
    void displayInfo() const;
};

