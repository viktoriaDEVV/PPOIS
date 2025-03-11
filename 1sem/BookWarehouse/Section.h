#pragma once
#include <iostream>

using namespace std;

class Section
{
private:
    string name;
    int amountBook;
public:
   
    Section(const string& sectionName, int initialAmount);
    string getName() const;
    void addBooks(int count);
    int getAmountBook() const;
    void printSectionDetails() const;
};