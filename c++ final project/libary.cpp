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
    int pc, check;
    string t, a, g, id;

    cout << "Enter the new books bookID: " << endl;
    cin >> id;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == id) {
            check += 1;
        }
    }

    if (check > 0) {
        cout << "id invalid re enter"
        cout << "Enter the new books bookID: " << endl;
        cin >> id;
    }
    
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

    for (size_t i = 0; i < books.size(); i++) {
        if (members[i].getMemberID() == id) {
            check += 1;
        }
    }

    if (check > 0) {
        cout << "Enter the Member ID: " << endl;
        cin >> id;
    }

    cout << "Enter members name: " << endl;
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
        cout << members[i] << endl;
    }
}

void Libary::borrowBook(){
    string bookBorID;
    cout << "Enter book ID of book to be borrowed: " << endl;
    cin >> bookBorID;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == bookBorID) {
            Book bookToBor = books[i]
        }
    }

    if (bookToBor.getAvaliability() == true) {
        cout << "Book has been borrowed" << endl;
        bookToBor.borrowBook(bookToBor);
    } else 
        cout << "book is aleady being borrowed" << endl;

}

void Libary::returnBook() {
    string bookRetID;
    cout << "Enter book ID of book to be returned: " << endl;
    cin >> bookRetID;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == bookRetID) {
            Book bookToRet = books[i]
        }
    }

    if (bookToRet.getAvaliability() == false) {
        cout << "Book has been returned" << endl;
        bookToRet.returnBook(bookToRet);
    } else 
        cout << "book is not being borrowed" << endl;
}



