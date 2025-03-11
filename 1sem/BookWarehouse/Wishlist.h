#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

class Wishlist {
private:
    unordered_set<string> bookTitles;

public:

    void addToWishlist(const string& title);
    void displayWishlist() const;
    size_t getBookCount() const;
    bool hasBook(const string& title) const;
};