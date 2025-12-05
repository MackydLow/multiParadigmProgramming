#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#include "member.h"
using namespace std;

class Libary {
    private:
        std::vector<Book> books;
        std::vector<Member> members;
    public:
        void addBook();
        void removeBook();
        void searchByTitle();
        void searchByID();
        void displayAvliableBook();
};

void Libary::addBook() {
    int pc;
    string t, a, g, id;

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

    books.[books.size()] = newBook;
}

void Libary::removeBook() {
    int id;
    cout << "Enter bookID of book to be deleted: " << endl;
    cin >> id;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == id) {
            cout << i << endl;
            books.erase(books.begin() + i);
        }
    }
}

void Libary::searchByTitle() {
    string name;
    cout << "input title to search" << endl;
    cin >> name;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == name) {
            books[i].displayBookInfo();
        }
    }

}

void Libary::searchByID() {
    string id;
    cout << "input book ID to search" << endl;
    cin >> id;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == id) {
            books[i].displayBookInfo();
        }
    }
}

void Libary::displayAvliableBook() {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getAvaliability() == true) {
            books[i].displayBookInfo();
        }
    }
}

void Libary::addMember() {
    string n, id;

    cout << "Enter the Member ID: " << endl;
    cin >> id;

    cout << "Enter the name of member: " << endl;
    cin >> n;

    Member newMember(id, n);

    members.[members.size()] = newMember;

}

void Libary::removeMember() {
    string id;
    cout << "Enter member ID of member to be deleted: " << endl;
    cin >> id;

    for (size_t i = 0; i < members.size(); i++) {
        if (members[i].getMemberID() == id) {
            cout << i << endl;
            members.erase(members.begin() + i);
        }
    }
}

void Libary::displayMembers() {
    for (size_t i = 0; i < members.size(); i++) {
        count << members[1] << endl;
    }
}



