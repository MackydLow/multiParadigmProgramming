#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
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
        void addMember();
        void removeMember();
        void displayMembers();
        void borrowBook();
        void returnBook();
        void loadBooks();
        void loadMembers();
        void saveBooksToFile();
        void saveMembersToFile();
};

void Libary::addBook() {
    int pc = 0, check = 0;
    string t, a, g, id;

    cout << "Enter the new books bookID: " << endl;
    cin >> id;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == id) {
            check += 1;
        }
    }

    if (check > 0) {
        cout << "id invalid re enter" << endl;
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

    books[books.size()] = newBook;
}

void Libary::removeBook() {
    string id;
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
    int check = 0;
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

    members[members.size()] = newMember;

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
        members[i].displayMemb();
    }
}

void Libary::borrowBook(){
    string bookBorID;
    cout << "Enter book ID of book to be borrowed: " << endl;
    cin >> bookBorID;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == bookBorID) {
            if (bookToBor.getAvaliability() == true) {
                cout << "Book has been borrowed" << endl;
                books[i].setAvaliability(false);
            } else 
                cout << "book is aleady being borrowed" << endl;
        }
    }

}

void Libary::returnBook() {
    string bookRetID;
    cout << "Enter book ID of book to be returned: " << endl;
    cin >> bookRetID;

    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getBookID() == bookRetID) {
             if (bookToRet.getAvaliability() == false) {
                cout << "Book has been returned" << endl;
                bookToRet.returnBook(bookToRet);
        } else 
                cout << "book is not being borrowed" << endl;
        }
    }

}

void Libary::loadBooks(){
    ifstream reader("books.txt");

    if (!reader) {
        cout << "Error opening input file" << endl;
        return 1;
    }

    string line;

    while (getLine(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);

        string id, title, author, genre, pageCount;

        getLine(ss, id, ',');
        getLine(ss, title, ',');
        getLine(ss, author, ',');
        getLine(ss, genre, ',');
        getLine(ss, pageCount, ',');

        int pageNumb = stoi(pageCount);

        Book b(id, title, author, genre, pageNumb, true);
    }

    file.close();
    return books;
}

void Libary::loadMembers() {
    ifstream file(members.txt)

    if (!reader) {
        cout << "Error opening input file" << endl;
        return 1;
    }

    string line;

    while (getLine(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);

        string id, name;

        getLine(ss, id, ',');
        getLine(ss, name, ',');;

        Member m(id, name);
    }

    file.close();
    return Members;
}

void saveBooksToFile() {
    ofstream writer("books.txt");

    if (!writer) {
        cout << "Error opening file" << endl;
        return;
    }

    for (const auto &b : books) {
        b.saveToFile(writer);
    }

    writer.close();
}

void Libary::saveMembersToFile() {
    ofstream writer("members.txt");

    if (!writer) {
        cout << "Error opening file" << endl;
        return;
    }

    for (const auto &m : members) {
        m.saveToFile(writer);
    }

    writer.close();
}

cout << mem