#ifndef UNTITLED9_PERSON_H
#define UNTITLED9_PERSON_H

#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string Name;
    Date Date_of_birth;

public:
    Person();
    Person(string name, Date date_of_birth);

    string getName();
    Date getDate_of_birth();

    void setName(string name);
    void setDate_of_birth(Date date_of_birth);

    virtual int getid() = 0;
    virtual void print();

    virtual ~Person();
};

#endif
