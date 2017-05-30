// 603_time.cpp

#include <iostream>
#include <iomanip>

using namespace std;

class timew
{
private:
    int hour, min, sec;
public:
    timew() : hour(0), min(0), sec(0)
    {}
    timew(int h, int m, int s) : hour(h), min(m), sec(s)
    {}
    void display() const {
        cout << hour << ":" << setw(2) << setfill('0') << min << ":"
             << setw(2) << setfill('0') << sec;
    }
    void sum_time (timew tt1, timew tt2){
        unsigned int total_sec;
        total_sec = tt1.hour * 3600 + tt1.min * 60 + tt1.sec +
                    tt2.hour * 3600 + tt2.min * 60 + tt2.sec;
        hour = total_sec / 3600;
        min = (total_sec - hour * 3600) / 60;
        sec = total_sec - hour*3600 - min*60;
    }
};

int main()
{
    timew tt1(20, 68, 55); const timew tt2(10, 48, 50); timew tt3;
    cout << "t1: "; tt1.display(); cout << endl;
    cout << "t2: "; tt2.display(); cout << endl;
    cout << "t3: "; tt3.display(); cout << endl;
    cout << "Складываю t3 = t1 + t2..." << endl;
    tt3.sum_time(tt1, tt2);
    cout << "Складываю t1 = t1 + t3..." << endl;
    tt1.sum_time(tt1, tt3);
    cout << "t1: "; tt1.display(); cout << endl;
    cout << "t2: "; tt2.display(); cout << endl;
    cout << "t3: "; tt3.display(); cout << endl;
    return 0;
}