#include "CourseRegistration.h"
#include "Course.h"
#include <iostream>
using namespace std;

CourseRegistration::CourseRegistration() : Course() {
    maxSize = 0;
    Number_of_students_enrolled = 0;
    studentIDs = nullptr;
}

CourseRegistration::CourseRegistration(string d, int c, string n, string p, int m) : Course(d, c, n, p) {
    maxSize = m;
    Number_of_students_enrolled = 0;

    studentIDs = new int[maxSize];

    for (int i = 0; i < maxSize; i++) {
        studentIDs[i] = 0;
    }
}

int CourseRegistration::getNumber_of_students_enrolled() {
    return Number_of_students_enrolled;
}

int CourseRegistration::getmaxSize() {
    return maxSize;
}

void CourseRegistration::setmaxSize(int m) {
    maxSize = m;
}

void CourseRegistration::setNumber_of_students_enrolled(int n) {
    Number_of_students_enrolled = n;
}

int CourseRegistration::registerStudent(int studentID) {
    if (Number_of_students_enrolled >= maxSize) {
        cout << "Course is full." << endl;
        return 0;
    }

    for (int i = 0; i < Number_of_students_enrolled; i++) {
        if (studentIDs[i] == studentID) {
            cout << "Student is already registered in this course." << endl;
            return 0;
        }
    }

    studentIDs[Number_of_students_enrolled] = studentID;
    Number_of_students_enrolled++;

    cout << "Student registered to course." << endl;
    return 1;
}

int CourseRegistration::removeStudent(int studentID) {
    for (int i = 0; i < Number_of_students_enrolled; i++) {
        if (studentIDs[i] == studentID) {
            for (int j = i; j < Number_of_students_enrolled - 1; j++) {
                studentIDs[j] = studentIDs[j + 1];
            }

            studentIDs[Number_of_students_enrolled - 1] = 0;
            Number_of_students_enrolled--;

            cout << "Student removed from course." << endl;
            return 1;
        }
    }

    cout << "Student was not found in this course." << endl;
    return 0;
}

bool CourseRegistration::isStudentInCourse(int Student_ID) {
    for (int i = 0; i < Number_of_students_enrolled; i++) {
        if (studentIDs[i] == Student_ID) {
            return true;
        }
    }

    return false;
}

void CourseRegistration::print() {
    Course::print();

    cout << "Maximum size: " << maxSize << endl;
    cout << "Number of students enrolled: " << Number_of_students_enrolled << endl;

    cout << "Student IDs: ";
    for (int i = 0; i < Number_of_students_enrolled; i++) {
        cout << studentIDs[i] << " ";
    }
    cout << endl;
}

CourseRegistration::~CourseRegistration() {
    delete[] studentIDs;
    cout << "CourseRegistration object deleted." << endl;
}
