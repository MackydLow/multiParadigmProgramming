#include <iostream>
#include <string>
#ifndef "book.h"
#include "book.h"
#include "member.h"
#include <vector>
using namespace std;

class Member {
    private:
        int memberID;
        string name;
        std::vector<Book> currentBorrow;
    public:
        int getMemberID();
        string getName();
        void setMemberID(int newMemberID);
        void setName(string newName);
        void borrowBook(Book &book);
        void returnBook(Book &book);

};