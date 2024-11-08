#include "Review.h"

Review::Review(const Book& book, const string& reviewerName, int rating)
        : book(book), reviewerName(reviewerName), rating(rating) {}

    void Review::displayReview() const {
             cout << "Review for: " << book.title << "\n"
                  << "Reviewer: " << reviewerName << "\n"
                  << "Rating: " << rating << "\n";
    }

const string& Review::getReviewerName() const { 
    return reviewerName; 
    }
    int Review::getRating() const { 
        return rating; 
        }
    const Book& Review::getBook() const {
         return book; 
         }