#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include <algorithm>

using namespace std;

class Worker
{
    string name;
    double salary;
public:
    Worker(const string& workerName, double workerSalary);
    string getName() const;
    double getSalary() const;
    void displayInfo() const;
    void TakeSalary(double* budget);
    void Sort(vector<Book>& books);
    void printBooks(const vector<Book>& books) const;

};