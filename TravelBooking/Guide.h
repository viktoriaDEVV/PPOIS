#pragma once
#include <iostream>

using namespace std;

class Guide {
public:
    string name;
    string language;
    double fee;

    Guide(const string& name, const string& language, double fee);
    string getGuideInfo() const;
};