#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        int bookID;
        string title;
        string author;
        string genre;
        int pageCount;
        bool avaliable;
    public:
        int getBookID();
        void setBookID(int newBookID);

        string getTitle();
        void setTitle(string newTitle);

        string getAuthor();
        void setAuthor(string newAuthor);

        string getGenre();
        void setGenre(string newGenre);

        int getPageCount();
        void setPageCount(int newPageCount);

        bool getAvaliability();
        void setAvaliability(bool newAvaliability);

        Book(int newBookID, string newTitle, string newAuthor, string newGenre, int newPageCount, bool newAvaliability);

        void displayBookInfo();
};