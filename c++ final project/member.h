#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#ifndef MEMBER_H
#define MEMBER_H
using namespace std;

class Member{
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
#endif