#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <string>
using namespace std;

class Publication {
    private:
        string pubID;
        string title;
        bool avaliable
    public:
        Publication(string pubID = "", string title = "", bool avaliable = true);
        string getPubID() const;
        string getTitle() const;
        bool avaliability() const;
        void setAvaliability(bool newAvalb);
        virtual void display();
        virtual void save(ofstream &w)
};

Publication::Publication(string pubID = "", string title = "", bool avaliable = true)
    : id(id), title(title), avaliable(avaliable) {}

string Publication::getPubID() const {
    return pubID;
}

string Publication::getTitle() const {
    return title;
}

bool Publication::avaliability() const {
    return avaliable;
}

void Publication::setAvaliability(bool newAvalb) {
    avaliable = newAvalb;
}

virtual void Publication::display() {
    const = 0;
}
virtual void Publication::save(ofstream &w) {
    const = 0;
}
#endif