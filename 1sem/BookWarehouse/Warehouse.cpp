#include "Warehouse.h"

Warehouse::Warehouse(int warehouseArea, const string& warehouseStreet, double initialBudget)
        : area(warehouseArea), street(warehouseStreet), amountBook(0), budget(initialBudget) {}

    void Warehouse::addBooks(int count) {
        amountBook += count;
        cout << count << " books added to warehouse. Total: " << amountBook << "\n";
    }

    void Warehouse::printWarehouseDetails() const {
        cout << "Warehouse Area: " << area << " sq.m\n";
        cout << "Street: " << street << "\n";
        cout << "Amount of Books: " << amountBook << "\n";
        cout << "Budget: $" << budget << "\n";
    }

    void Warehouse::updateBudget(double amount) {
        budget += amount;
        cout << "Budget updated. New Budget: $" << budget << "\n";
    }

    void Warehouse::removeBooks(int count) {
        if (count > amountBook) {
            cout << "Error: Cannot remove more books than available in the warehouse.\n";
        } else {
            amountBook -= count;
            cout << count << " books removed from warehouse. Total: " << amountBook << "\n";
        }
    }

    int Warehouse::getAmountBook() const {
        return amountBook;
    }

    int Warehouse::getArea() const {
        return area;
    }

    string Warehouse::getStreet() const {
        return street;
    }

    double Warehouse::getBudget() const {
        return budget;
    }