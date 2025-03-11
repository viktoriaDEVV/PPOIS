#include "Delivery.h"

    Delivery::Delivery(const string& batchNum, const Date& date, int amount, const Provider& prov)
        : batchNumber(batchNum), deliveryDate(date), amountBook(amount), provider(prov) {}


string Delivery::getBatchNumber() const {
        return batchNumber;
    }

    Date Delivery::getDeliveryDate() const {
        return deliveryDate;
    }

    int Delivery::getAmountBook() const {
        return amountBook;
    }

    Provider Delivery::getProvider() const {
        return provider;
    }

    // Сеттеры
    void Delivery::setBatchNumber(const string& batchNum) {
        batchNumber = batchNum;
    }

    void Delivery::setDeliveryDate(const Date& date) {
        deliveryDate = date;
    }

    void Delivery::setAmountBook(int amount) {
        amountBook = amount;
    }

    void Delivery::setProvider(const Provider& prov) {
        provider = prov;
    }

    void Delivery::printDeliveryDetails() const {
        cout << "Batch Number: " << batchNumber << "\n";
        cout << "Delivery Date: " << deliveryDate.day << "-" << deliveryDate.month << "-" << deliveryDate.year << "\n";
        cout << "Amount of Books: " << amountBook << "\n";
        provider.printProviderDetails();
    }

    void Delivery::updateAmount(int newAmount) {
        amountBook = newAmount;
        cout << "Amount of books updated to " << amountBook << ".\n";
    }

    void Delivery::updateDeliveryDate(const Date& newDate) {
        deliveryDate = newDate;
        cout << "Delivery date updated to " << deliveryDate.day << "-" << deliveryDate.month << "-" << deliveryDate.year << ".\n";
    }

    bool Delivery::isDeliveryOnTime(const Date& currentDate) const {
        return (currentDate.year < deliveryDate.year || 
                (currentDate.year == deliveryDate.year && currentDate.month < deliveryDate.month) ||
                (currentDate.year == deliveryDate.year && currentDate.month == deliveryDate.month && currentDate.day <= deliveryDate.day));
    }

    void Delivery::confirmDelivery() {
        cout << "Delivery confirmed for batch number " << batchNumber << ".\n";
    }

