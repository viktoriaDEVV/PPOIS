#pragma once
#include <iostream>
#include "Book.h"

using namespace std;

class Review
{
private:
    Book book;
    string reviewerName;
    int rating; // Рейтинг от 1 до 5

public:
    Review(const Book& book, const string& reviewerName, int rating);
    const string& getReviewerName() const;
    const Book& getBook() const;
    int getRating() const;
    void displayReview() const;
};