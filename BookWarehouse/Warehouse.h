#pragma once
#include <iostream>

using namespace std;

class Warehouse
{
private:
    int area;
    string street;
    int amountBook;
    double budget;
public:
    
    Warehouse(int warehouseArea, const string& warehouseStreet, double initialBudget);
    void addBooks(int count);
    void removeBooks(int count);
    int getAmountBook() const;
    int getArea() const;
    string getStreet() const;
    double getBudget() const;
    void printWarehouseDetails() const;
    void updateBudget(double amount);
};