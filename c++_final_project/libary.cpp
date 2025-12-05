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
        std::vector<Publication*> Publications;
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

//addd book
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

    Publication* newPub = new Book(id, t, a, g, pc, true);

    publications.push_back(newPub);
}

//remove book
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

//serach for books by title
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

//search for books by id
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

//display books that are avaliable to borrow
void Libary::displayAvliableBook() {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getAvaliability() == true) {
            books[i].displayBookInfo();
        }
    }
}

//add new ,ember
void Libary::addMember() {
    string n, id;
    cout << "Enter the Member ID: " << endl;
    cin >> id;

    cout << "Enter members name: " << endl;
    cin >> n;

    Member newMember(id, n);

    members.push_back(newMember);

}

//remove member
void Libary::removeMember() {
    string id;
    cout << "Enter member ID of member to be deleted: " << endl;
    cin >> id;

    for (size_t i = 0; i < members.size(); i++) {
        if (members[i].getMemberID() == id) {
            members.erase(members.begin() + i);
            return;
        }
    }
    cout << "Member not found re try" << endl;
}

//display member
void Libary::displayMembers() {
    if (members.empty()) {
        cout << "No members found" << endl;
    }
    for (const Member &newMemb : members) {
        newMemb.displayMemb();
    }
}

//borrow a book
void Libary::borrowBook(){
    string bookBorID;
    cout << "Enter book ID of book to be borrowed: " << endl;
    cin >> bookBorID;

    for (Publication* &p : publications) {
        book* newBook = dynamic_cast<Book*>(p);
        if (newBook && newBook->getBookID() == bookBorID) {
            if (b.getAvaliability() == true) {
                cout << "Book has been borrowed" << endl;
                b.setAvaliability(false);
            } else 
                cout << "book is aleady being borrowed" << endl;
        }
    }

}

//return a book
void Libary::returnBook() {
    string bookRetID;
    cout << "Enter book ID of book to be returned: " << endl;
    cin >> bookRetID;

    for (Publication* &p : publications) {
        Book* retBook = dynamic_cast<Book*>(p);
        if (retBook && retBook->getBookID() == bookRetID) {
             if (b.getAvaliability() == false) {
                cout << "Book has been returned" << endl;
                b.setAvaliability(true);
        } else 
                cout << "book is not being borrowed" << endl;
        }
    }

}

//load a book
void Libary::loadBooks(){

    ifstream file("books.txt");

    if (!file) {
        cout << "Error opening input file" << endl;
        return;
    }

    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);

        string id, title, author, genre, pageCount;

        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, genre, ',');
        getline(ss, pageCount, ',');

        int pageNumb = stoi(pageCount);

        Publication* newPub = new Book(id, title, author, genre, pageNumb, true);

        publication.push_back(b);
    }

    file.close();
}

//load a member from file
void Libary::loadMembers() {
    ifstream file("members.txt");

    if (!file) {
        cout << "Error opening input file" << endl;
        return;
    }

    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);

        string id, name;

        getline(ss, id, ',');
        getline(ss, name, ',');;

        Member m(id, name);

        members.push_back(m);
    }

    file.close();
}

save all books to file
void Libary::saveBooksToFile() {
    ofstream writer("books.txt");

    if (!writer) {
        cout << "Error opening file" << endl;
        return;
    }

    for (Publication* p : Publication) {
        Book newBook = dynamic_cast<Book*>(p):
        if (newBook) newBook->(writer);
    }

    writer.close();
}

//save all memebrs ro file
void Libary::saveMembersToFile() {
    ofstream writer("members.txt");

    if (!writer) {
        cout << "Error opening file" << endl;
        return;
    }

    for (const auto &m : members) {
        m.saveMember(writer);
    }

    writer.close();
}

//save books to file
void Book::saveBook(ofstream &writer) const {
    writer << bookID << ","
    << title << ","
    << author << ","
    << genre << ","
    << endl;
}

int main () {

    libary l;
    l.addBook();
    l.removeBook();
    l.searchByTitle();
    l.searchByID();
    l.displayAvliableBook();
    l.addMember();
    l.removeMember();
    l.displayMembers();
    l.borrowBook();
    l.returnBook();
    l.loadBooks();
    l.loadMembers();
    l.saveBooksToFile();
    l.saveMembersToFile();
}