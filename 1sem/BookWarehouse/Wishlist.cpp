#include "Wishlist.h"

void Wishlist::addToWishlist(const string& title) {
        bookTitles.insert(title);
    }

    void Wishlist::displayWishlist() const {
        cout << "Wishlist:\n";
        for (const auto& title : bookTitles) {
            cout << "- " << title << "\n";
        }
    }

    size_t Wishlist::getBookCount() const {
        return bookTitles.size();
    }

    bool Wishlist::hasBook(const string& title) const {
        return bookTitles.find(title) != bookTitles.end();
    }