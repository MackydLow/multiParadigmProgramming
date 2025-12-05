#include <iostream>
#include <string>
#ifndef "book.h"
#include "book.h"
#include "member.h"
#include <vector>
using namespace std;
 
//getters
int Member::getMemberID(){
     return memberID;
}

string Member::getName(){
     return name;
}

//setters
void Member::setMemberID(int newMemberID) {
    memberID = newMemberID;
}

void Member::setName(string newName) {
    name = newName;
}

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


