#ifndef UNTITLED9_PROFESSOR_H
#define UNTITLED9_PROFESSOR_H

#include "Person.h"
#include "Date.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

class GraduateStudent;

class Professor : public Person {
private:
    int Employee_ID;
    Date employment_date;
    static int nextEmployeeID;

public:
    Professor();
    Professor(string name, Date birth, Date e);

    int getEmployee_ID();
    Date getEmployment_date();

    void setEmployee_ID(int e);
    void setEmployment_date(Date d);

    int getid();

    virtual int add_course(Course* c) = 0;
    virtual int addGraduateStudent(GraduateStudent* g);

    virtual void print();

    virtual ~Professor();
};

#endif
