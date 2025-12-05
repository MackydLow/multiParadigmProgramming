#include <iostream>
#include <string>
#include "publication.h"
#ifndef BOOK_H
#define BOOK_H
using namespace std;

class Book : Publication{
    private:
        string bookID;
        string title;
        string author;
        string genre;
        int pageCount;
        bool avaliable;
    public:
        string getBookID();
        void setBookID(string newBookID);

        string getTitle();
        void setTitle(string newTitle);

        string getAuthor();
        void setAuthor(string newAuthor);

        string getGenre();
        void setGenre(string newGenre);

        int getPageCount();
        void setPageCount(int newPageCount);

        bool getAvaliability();
        void setAvaliability(bool newAvaliability);

        Book(string newBookID, string newTitle, string newAuthor, string newGenre, int newPageCount, bool newAvaliability);

        void displayBookInfo();

        void saveBook(ofstream &writer) const;
};
#endif