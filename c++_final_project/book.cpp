#include <iostream>
#include <string>
#include "book.h"
using namespace std;

//getters
string Book::getBookID(){
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
void Book::setBookID(string newBookID) {
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
Book::Book(string newBookID, string newTitle, string newAuthor, string newGenre, int newPageCount, bool newAvaliability) {
    cout << "adding a new book" << endl;
    bookID = newBookID;
    title = newTitle;
    author = newAuthor;
    genre = newGenre;
    pageCount = newPageCount;
    avaliable = newAvaliability;
};

//print book
void Book::displayBookInfo() {
    cout << "Book ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "Avaliability: " << avaliable << endl;
}


