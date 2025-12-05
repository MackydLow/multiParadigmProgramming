class Magazine : public Publication {
    private:
        int issue
    public:
        Magazine(stringpPubID = "", string title = "", int issue = 0)
            : Publication (id, title, true), issue(issue) {}

        void display() const override {
            cout << "Magazine: " << title << " issue: " << issue << endl;
        }

        void save (ofstream &w) const override {
            w << "Magazine, " << id << " , " << title << " , " << issue << endl;
        }
};