#include <iostream>
#include <string>
#include "member.h"
#include <vector>
using namespace std;
 
//getters
string Member::getMemberID(){
     return memberID;
}

string Member::getName(){
     return name;
}

//setters
void Member::setMemberID(string newMemberID) {
    memberID = newMemberID;
}

void Member::setName(string newName) {
    name = newName;
}

//constructor
Member::Member(int newMemberID, string newName) {
    cout << "adding a new member" << endl;
    memberID = newMemberID;
    name = newName;
};

//functions
void Member::borrowBook(Book &book) {
    currentBorrow[currentBorrow.size()] = book;

    book.setAvaliability(false);
}

void Member::returnBook(Book &book) {
    for (size_t i = 0; i < currentBorrow.size(); i++) {
        if (currentBorrow[i].getBookID() == book.getBookID()) {
            cout << i << endl;
            currentBorrow.erase(currentBorrow.begin() + i);
        }
    }

}


