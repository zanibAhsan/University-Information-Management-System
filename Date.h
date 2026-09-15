#ifndef UNTITLED9_DATE_H
#define UNTITLED9_DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int m, int d, int y);

    int getmonth();
    int getday();
    int getyear();

    void setmonth(int m);
    void setday(int d);
    void setyear(int y);

    void print();

    ~Date();
};

#endif
