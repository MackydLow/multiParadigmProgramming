#include "intlist.h"

// Constructor
Intlist::Intlist() : Head(nullptr) {}

// Destructor
Intlist::~Intlist() {
    Node* temp;
    while (Head != nullptr) {
        temp = Head;
        Head = Head->Next;
        delete temp;
    }
}

// Check if list is empty
bool Intlist::Empty() const {
    return Head == nullptr;
}

// Insert at the beginning
bool Intlist::Insert(const int& new_element) {
    Node* new_node = new Node(new_element, Head);
    Head = new_node;
    return true;
}

// Delete a specific element
bool Intlist::Delete(const int& del_element) {
    if (Empty())
        return false;

    Node* temp = Head;

    // Case 1: delete head node
    if (Head->Element == del_element) {
        Head = Head->Next;
        delete temp;
        return true;
    }

    // General case: search for node
    Node* previous = Head;
    temp = Head->Next;

    while (temp != nullptr && temp->Element != del_element) {
        previous = temp;
        temp = temp->Next;
    }

    if (temp == nullptr)
        return false;  // not found

    previous->Next = temp->Next;
    delete temp;
    return true;
}

// Print the list
void Intlist::Print(std::ostream& out_stream) const {
    Node* temp = Head;
    while (temp != nullptr) {
        out_stream << temp->Element << " ";
        temp = temp->Next;
    }
}

// Output operator overload
std::ostream& operator<<(std::ostream& out_stream,
                         const Intlist& out_list) {
    out_list.Print(out_stream);
    return out_stream;
}