#include <iostream>
#include <string>
#include <vector>
#include "book.h"
//#include "member.h"
using namespace std;

class Libary {
    private:
        std::vector<Book> books;
        //std::vector<Member> members;
    public:
        void addBook();
        void removeBook();
};

void Libary::addBook() {
    int id, pc;
    string t, a, g;

    cout << "Enter the new books bookID: " << endl;
    cin >> id;

    cout << "Enter the new books title: " << endl;
    cin >> t;

    cout << "Enter the author of the new book: " << endl;
    cin >> a;

    cout << "Enter the new books genre: " << endl;
    cin >> g;

    cout << "Enter the new books page count: " << endl;
    cin >> pc;

    Book newBook(id, t, a, g, pc, true);

}

void Libary::removeBook() {
    int id;
    cout << "Enter bookID of book to be deleted: " << endl;
    cin >> id;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == id) {
            print(books.begin() + i);
            books.erase(books.begin() + i);
        }
    }
}

void Libary::searchByTitle() {
    string name;
    cout << "input title to search" << endl;
    cin >> name

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == name) {
            cout << books[books.begin() + i].displayBookInfo << endl;
        }
    }

}