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
        string getMemberID();
        string getName();
        void setMemberID(string newMemberID);
        void setName(string newName);
        void borrowBook(Book &book);
        void returnBook(Book &book);

        Member(string newMemberID, string newName)
};
#endif