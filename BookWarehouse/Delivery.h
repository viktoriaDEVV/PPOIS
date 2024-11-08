#pragma once
#include <iostream>
#include "Date.h"
#include "Provider.h"

using namespace std;

class Delivery
{
    string batchNumber;
    Date deliveryDate;
    int amountBook;
    Provider provider;
public:

    Delivery(const string& batchNum, const Date& date, int amount, const Provider& prov);
    string getBatchNumber() const;
    Date getDeliveryDate() const;
    int getAmountBook() const;
    Provider getProvider() const;
    void setBatchNumber(const string& batchNum);
    void setDeliveryDate(const Date& date);
    void setAmountBook(int amount);
    void setProvider(const Provider& prov);
    void printDeliveryDetails() const;
    void updateAmount(int newAmount);
    void updateDeliveryDate(const Date& newDate);
    bool isDeliveryOnTime(const Date& currentDate) const;
    void confirmDelivery();
};