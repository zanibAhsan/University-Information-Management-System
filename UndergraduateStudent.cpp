#include "UndergraduateStudent.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
using namespace std;

UndergraduateStudent::UndergraduateStudent() : Student() {
    Number_of_courses = 0;

    for (int i = 0; i < 4; i++) {
        pt[i] = nullptr;
    }
}

UndergraduateStudent::UndergraduateStudent(string name, Date birth, Date e) : Student(name, birth, e) {
    Number_of_courses = 0;

    for (int i = 0; i < 4; i++) {
        pt[i] = nullptr;
    }
}

int UndergraduateStudent::getNumber_of_courses() {
    return Number_of_courses;
}

void UndergraduateStudent::setNumber_of_courses(int n) {
    Number_of_courses = n;
}

int UndergraduateStudent::add_course(Course* c) {
    if (Number_of_courses >= 4) {
        cout << "Undergraduate student cannot take more than 4 courses." << endl;
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == c->getCourse_number()) {
            cout << "Student is already registered in this course." << endl;
            return 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (pt[i] == nullptr) {
            pt[i] = c;
            Number_of_courses++;
            cout << "Course added to undergraduate student." << endl;
            return 1;
        }
    }

    return 0;
}

int UndergraduateStudent::remove_course(int courseNumber) {
    for (int i = 0; i < 4; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == courseNumber) {
            pt[i] = nullptr;
            Number_of_courses--;
            cout << "Course removed from undergraduate student." << endl;
            return 1;
        }
    }

    cout << "Course was not found in undergraduate student courses." << endl;
    return 0;
}

bool UndergraduateStudent::isCourseInStudent(int courseNumber) {
    for (int i = 0; i < 4; i++) {
        if (pt[i] != nullptr && pt[i]->getCourse_number() == courseNumber) {
            return true;
        }
    }

    return false;
}

void UndergraduateStudent::print() {
    cout << "Undergraduate Student:" << endl;
    Student::print();

    cout << "Number of courses: " << Number_of_courses << endl;

    cout << "Registered courses:" << endl;
    for (int i = 0; i < 4; i++) {
        if (pt[i] != nullptr) {
            pt[i]->print();
        }
    }
}

UndergraduateStudent::~UndergraduateStudent() {
    cout << "UndergraduateStudent object deleted." << endl;
}
