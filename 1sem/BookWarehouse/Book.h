#pragma once
#include <iostream>

using namespace std;

class Book
{
public:
    string title;
    string author;
    int publicationYear;
    string genre;

    Book(const string& bookTitle, const string& bookAuthor, int pubYear, const string& bookGenre);
};