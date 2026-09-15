#ifndef UNTITLED9_FULLTIMEPROFESSOR_H
#define UNTITLED9_FULLTIMEPROFESSOR_H

#include "Professor.h"
#include "GraduateStudent.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

class FullTimeProfessor : public Professor {
private:
    int Number_of_supervised_students;
    int Number_of_courses;
    GraduateStudent* supervised_students[10];
    Course* pt[2];

public:
    FullTimeProfessor();
    FullTimeProfessor(string name, Date birth, Date e);

    int getNumber_of_supervised_students();
    int getNumber_of_courses();

    void setNumber_of_supervised_students(int n);
    void setNumber_of_courses(int n);

    int add_course(Course* c);
    int addGraduateStudent(GraduateStudent* g);

    void print();

    ~FullTimeProfessor();
};

#endif
