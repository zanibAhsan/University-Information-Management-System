#ifndef UNTITLED9_GRADUATESTUDENT_H
#define UNTITLED9_GRADUATESTUDENT_H

#include "Student.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

class GraduateStudent : public Student {
private:
    int Number_of_courses;
    Course* pt[2];

public:
    GraduateStudent();
    GraduateStudent(string name, Date birth, Date e);

    int getNumber_of_courses();
    void setNumber_of_courses(int n);

    bool isGraduateStudent();

    int add_course(Course* c);
    int remove_course(int courseNumber);
    bool isCourseInStudent(int courseNumber);

    void print();

    ~GraduateStudent();
};

#endif
