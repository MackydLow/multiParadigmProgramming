#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

class Intlist {
private:
    // Node structure
    class Node {
    public:
        int Element;
        Node* Next;

        Node(int element = 0, Node* next = nullptr)
            : Element(element), Next(next) {}
    };

    Node* Head;

public:
    Intlist();
    ~Intlist();

    bool Empty() const;
    bool Insert(const int& new_element);
    bool Delete(const int& del_element);
    void Print(std::ostream& out_stream) const;

    // Overloaded output operator
    friend std::ostream& operator<<(std::ostream& out_stream,
                                    const Intlist& out_list);
};

#endif
