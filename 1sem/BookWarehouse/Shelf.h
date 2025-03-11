#pragma once
#include <iostream>
#include "Section.h"

using namespace std;

class Shelf
{
private:
    int number;
    Section section;
    int capacity;
public:

    Shelf(int shelfNumber, const Section& sec, int shelfCapacity);
    int getNumber() const ;
    Section getSection() const;
    void addBooksToShelf(int count);
    void printShelfDetails() const;
};