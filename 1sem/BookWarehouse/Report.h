#pragma once
#include <iostream>
#include "Date.h"
#include "GivingOut.h"
#include "GivingBack.h"

using namespace std;

class Report
{
    Date reportDate;
public:
    
    Report(const Date& date);
    void MakeReport(const GivingOut& givingOut, const GivingBack& givingBack);
};