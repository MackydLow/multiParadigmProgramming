#include <iostream>
#include <string>
#include "member.h"
#include <vector>
using namespace std;
 template <typename publication>
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
void Member::borrowBook(publication* &pub) {
    currentBorrow[currentBorrow.size()] = book;

    book.setAvaliability(false);
}

void Member::returnBook(publication* &pub) {
    for (size_t i = 0; i < currentBorrow.size(); i++) {
        if (currentBorrow[i].getBookID() == book.getBookID()) {
            cout << i << endl;
            currentBorrow.erase(currentBorrow.begin() + i);
        }
    }
}

void Member::saveMember(ofstream &writer) const {
    writer << memberID << ","
    << name << ","
    << endl;

}

void Member::displayMemb() const {
    cout << "Member ID: " << memberID << endl;
    cout << "Name: " << name << endl;
    cout << " " << endl;
}


