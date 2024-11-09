#include "Worker.h"

    Worker::Worker(const string& workerName, double workerSalary)
        : name(workerName), salary(workerSalary) {}

    void Worker::TakeSalary(double* budget)
    {
        *budget -= salary;
    }

    void Worker::Sort(vector<Book>& books) {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.author < b.author;
        });
    }

    void Worker::printBooks(const vector<Book>& books) const {
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << "\n";
        }
    }
    string Worker::getName() const {
        return name;
    }

    double Worker::getSalary() const {
        return salary;
    }
    void Worker::displayInfo() const {
        cout << "Worker Name: " << name << ", Salary: $" << salary << endl;
    }