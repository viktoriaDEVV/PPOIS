#pragma once
#include <iostream>

using namespace std;

struct Date
{
public:
    int day;
    int month;
    int year;
    Date(int d, int m, int y);
    void Display() const;
};