#include "Book.h"

using namespace std;

Book::Book(const string& bookTitle, const string& bookAuthor, int pubYear, const string& bookGenre)
        : title(bookTitle), author(bookAuthor), publicationYear(pubYear), genre(bookGenre) {}
