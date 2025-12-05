#include <iostream>
#include <string>
#include "book.h"
#include "member.h"
using namespace std;

class Libary {
    private:
        Book books[];
        Member members[];
    public:
        void addBook();
};

void Libary::addBook() {
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