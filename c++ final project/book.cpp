#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        int bookID;
        string title;
        string author;
        string genre;
        int pageCount;
        bool avaliable;
    public:
        int getBookID();
        void setBookID(int newBookID);

        string getTitle();
        void setTitle(string newTitle);

        string getAuthor();
        void setAuthor(string newAuthor);

        string getGenre();
        void setGenre(int newGenre);

        int getPageCount();
        void setPageCount(int newPageCount);

        bool getAvaliability();
        void setAvaliability(bool newAvaliability);

        Book(int newBookID, string newTitle, string newAuthor, int newGenre, int newPageCount, bool newAvaliability);
};
//getters
int Book::getBookID(){
     return bookID;
}

string Book::getTitle(){
     return title;
}

string Book::getAuthor(){
    return author;
}

string Book::getGenre(){
    return genre;
}

int Book::getPageCount(){
    return pageCount;
}

bool Book::getAvaliability(){
    return avaliable;
}

//setters
void Book::setBookID(int newBookID) {
    bookID = newBookID;
}

void Book::setTitle(string newTitle) {
    title = newTitle;
}

void Book::setAuthor(string newAuthor) {
    author = newAuthor;
}

void Book::setGenre(int newGenre) {
    genre = newGenre;
}

void Book::setPageCount(int newPageCount) {
    pageCount = newPageCount;
}

void Book::setAvaliability(bool newAvaliability) {
    avaliable = newAvaliability;
}

//constructer
Book::Book(int newBookID, string newTitle, string newAuthor, int newGenre, int newPageCount, bool newAvaliability) {
    cout << "adding a new book" << endl;
    bookID = newBookID;
    title = newTitle;
    author = newAuthor;
    genre = newGenre;
    pageCount = newPageCount;
    avaliable = newAvaliability;
};
