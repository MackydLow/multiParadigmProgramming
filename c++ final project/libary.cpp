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

    cout << "Enter the new books bookID: ";
    cin >> id;

    cout << "Enter the new books title: ";
    cin >> t;

    cout << "Enter the author of the new book: ";
    cin >> a;

    cout << "Enter the new books genre: ";
    cin >> g;

    cout << "Enter the new books page count: ";
    cin >> pc;

    Book newBook(id, t, a, g, pc, true);

}

void Libary::removeBook() {
    int id;
    cout << "Enter the new books bookID: ";
    cin >> id;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID == id) {
            books.erase(books.begin() + i)
        }
    }
}