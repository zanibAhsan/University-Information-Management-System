#ifndef UNTITLED9_UNDERGRADUATESTUDENT_H
#define UNTITLED9_UNDERGRADUATESTUDENT_H

#include "Student.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

class UndergraduateStudent : public Student {
private:
    int Number_of_courses;
    Course* pt[4];

public:
    UndergraduateStudent();
    UndergraduateStudent(string name, Date birth, Date e);

    int getNumber_of_courses();
    void setNumber_of_courses(int n);

    int add_course(Course* c);
    int remove_course(int courseNumber);
    bool isCourseInStudent(int courseNumber);

    void print();

    ~UndergraduateStudent();
};

#endif
