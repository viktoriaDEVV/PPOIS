#include "Review.h"

Review::Review(const Client& clientInfo, const Destination& destinationInfo, const Rating& ratingValue, const string& reviewComment)
    : client(clientInfo), destination(destinationInfo), rating(ratingValue), comment(reviewComment) {}

    void Review::displayReviewDetails() const{
        client.displayInfo();
        destination.getSummary(); 
        cout << "Rating: " << rating.getValue() << endl;
        cout << "Comment: " << comment << endl;
    }

     void Review::updateComment(const string& newComment){
        comment = newComment;
     }