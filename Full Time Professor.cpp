#include "FullTimeProfessor.h"
#include "Professor.h"
#include "GraduateStudent.h"
#include "Course.h"
#include <iostream>
using namespace std;

FullTimeProfessor::FullTimeProfessor() : Professor() {
    Number_of_supervised_students = 0;
    Number_of_courses = 0;

    for (int i = 0; i < 10; i++) {
        supervised_students[i] = nullptr;
    }

    for (int j = 0; j < 2; j++) {
        pt[j] = nullptr;
    }
}

FullTimeProfessor::FullTimeProfessor(string name, Date birth, Date e) : Professor(name, birth, e) {
    Number_of_supervised_students = 0;
    Number_of_courses = 0;

    for (int i = 0; i < 10; i++) {
        supervised_students[i] = nullptr;
    }

    for (int j = 0; j < 2; j++) {
        pt[j] = nullptr;
    }
}

int FullTimeProfessor::getNumber_of_supervised_students() {
    return Number_of_supervised_students;
}

int FullTimeProfessor::getNumber_of_courses() {
    return Number_of_courses;
}

void FullTimeProfessor::setNumber_of_supervised_students(int n) {
    Number_of_supervised_students = n;
}

void FullTimeProfessor::setNumber_of_courses(int n) {
    Number_of_courses = n;
}

int FullTimeProfessor::add_course(Course* c) {
    if (Number_of_courses >= 2) {
        cout << "Full time professor cannot teach more than 2 courses." << endl;
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        if (pt[i] == nullptr) {
            pt[i] = c;
            Number_of_courses++;
            cout << "Course added to full time professor." << endl;
            return 1;
        }
    }

    return 0;
}

int FullTimeProfessor::addGraduateStudent(GraduateStudent* g) {
    if (Number_of_supervised_students >= 10) {
        cout << "Full time professor cannot supervise more than 10 graduate students." << endl;
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        if (supervised_students[i] == g) {
            cout << "Graduate student is already supervised by this professor." << endl;
            return 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (supervised_students[i] == nullptr) {
            supervised_students[i] = g;
            Number_of_supervised_students++;
            cout << "Graduate student added to professor supervision list." << endl;
            return 1;
        }
    }

    return 0;
}

void FullTimeProfessor::print() {
    cout << "Full Time Professor:" << endl;
    Professor::print();

    cout << "Number of courses teaching: " << Number_of_courses << endl;
    cout << "Courses teaching:" << endl;
    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr) {
            pt[i]->print();
        }
    }

    cout << "Number of graduate students supervised: " << Number_of_supervised_students << endl;
    cout << "Graduate students supervised:" << endl;
    for (int j = 0; j < 10; j++) {
        if (supervised_students[j] != nullptr) {
            cout << supervised_students[j]->getName() << " - ID: " << supervised_students[j]->getStudent_ID() << endl;
        }
    }
}

FullTimeProfessor::~FullTimeProfessor() {
    cout << "FullTimeProfessor object deleted." << endl;
}
