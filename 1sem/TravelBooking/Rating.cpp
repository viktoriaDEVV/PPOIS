#include "Rating.h"

Rating::Rating(const Client& clientInfo, double ratingValue)
        : client(clientInfo), rating(ratingValue) {
        validateRating();
    }
void Rating::validateRating() {
        if (rating < 0 || rating > 5) {
            cout << "Invalid rating! Rating must be between 0 and 5." << endl;
            rating = 0; 
        }
    }
void Rating::displayRatingDetails() const {
        client.displayInfo();
        cout << "Rating: " << rating << endl;
    }
int Rating::getValue() const {
        return rating;
    }