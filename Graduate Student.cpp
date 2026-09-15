#include "GraduateStudent.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
using namespace std;

GraduateStudent::GraduateStudent() : Student() {
    Number_of_courses = 0;

    for (int i = 0; i < 2; i++) {
        pt[i] = nullptr;
    }
}

GraduateStudent::GraduateStudent(string name, Date birth, Date e) : Student(name, birth, e) {
    Number_of_courses = 0;

    for (int i = 0; i < 2; i++) {
        pt[i] = nullptr;
    }
}

int GraduateStudent::getNumber_of_courses() {
    return Number_of_courses;
}

void GraduateStudent::setNumber_of_courses(int n) {
    Number_of_courses = n;
}

bool GraduateStudent::isGraduateStudent() {
    return true;
}

int GraduateStudent::add_course(Course* c) {
    if (Number_of_courses >= 2) {
        cout << "Graduate student cannot take more than 2 courses." << endl;
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == c->getCourse_number()) {
            cout << "Student is already registered in this course." << endl;
            return 0;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (pt[i] == nullptr) {
            pt[i] = c;
            Number_of_courses++;
            cout << "Course added to graduate student." << endl;
            return 1;
        }
    }

    return 0;
}

int GraduateStudent::remove_course(int courseNumber) {
    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == courseNumber) {
            pt[i] = nullptr;
            Number_of_courses--;
            cout << "Course removed from graduate student." << endl;
            return 1;
        }
    }

    cout << "Course was not found in graduate student courses." << endl;
    return 0;
}

bool GraduateStudent::isCourseInStudent(int courseNumber) {
    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == courseNumber) {
            return true;
        }
    }

    return false;
}

void GraduateStudent::print() {
    cout << "Graduate Student:" << endl;
    Student::print();

    cout << "Number of courses: " << Number_of_courses << endl;

    cout << "Registered courses:" << endl;
    for (int i = 0; i < 2; i++) {
        if (pt[i] != nullptr) {
            pt[i]->print();
        }
    }
}

GraduateStudent::~GraduateStudent() {
    cout << "GraduateStudent object deleted." << endl;
}
