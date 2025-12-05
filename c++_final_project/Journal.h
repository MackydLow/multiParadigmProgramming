class Journal : public Publication {
    private:
        int pages;
    public:
        journal(string pubID = "", string title = "", int pages = 0)
            : Publication(pubID, title, true), pages(pages) {}

        void display() const override {
            cout << "Journal: " << title << " page " << pages << endl;
        }

        void save(ofstream &w) const override {
            w << "journal, " << pubID << " , " << title << " , " << pages << endl;
        }
};