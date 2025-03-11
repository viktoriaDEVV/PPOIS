#pragma once
#include <iostream>
#include "Client.h"
#include "TravelAgent.h"

using namespace std;

class Contract {
public:
    string contractId;
    Client client;
    TravelAgent agent;
    string startDate;
    string endDate;
    double totalAmount;
    bool isSigned;

    Contract(const string& contractId, const Client& client, const TravelAgent& agent,
             const string& startDate, const string& endDate, double totalAmount);
    void signContract();
    void displayContractDetails() const ;
};