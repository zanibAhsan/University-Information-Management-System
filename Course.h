#ifndef UNTITLED9_COURSE_H
#define UNTITLED9_COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string Department;
    int Course_number;
    string Course_name;
    string Professor_name;

public:
    Course();
    Course(string d, int c, string n, string p);

    string getDepartment();
    int getCourse_number();
    string getCourse_name();
    string getProfessor_name();

    void setDepartment(string d);
    void setCourse_number(int c);
    void setCourse_name(string n);
    void setProfessor_name(string p);

    virtual void print();

    virtual ~Course();
};

#endif
