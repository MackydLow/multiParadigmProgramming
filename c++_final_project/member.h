#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#ifndef MEMBER_H
#define MEMBER_H
using namespace std;
template <typename publication>
class Member{
    private:
        string memberID;
        string name;
        std::vector<publiation*> currentBorrow;
    public:
        string getMemberID();
        string getName();
        void setMemberID(string newMemberID);
        void setName(string newName);
        void borrowBook(publication* &pub);
        void returnBook(publication* &pub);

        Member(string newMemberID, string newName);
        void saveMember(ofstream &writer) const;
        void displayMemb() const;
};
#endif