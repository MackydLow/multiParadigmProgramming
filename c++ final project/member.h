#include <iostream>
#include <string>
#include "member.cpp"
#include <vector>
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