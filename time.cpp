#include <iostream>
using namespace std;

class time {
    private:
        int hour;
        int minute;
        int second;
    public:
    time(int h, int m, int s);
    setTime(int h, int m, int s);
};

time::time(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}

void setTime(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
}

void display(int h, int m, int s) {
    cout << h << ":" << m << ":" << s <<endl;
}

main() {

}