#include "Student.h"
#include "Person.h"
#include "Course.h"
#include "Date.h"
#include <iostream>
using namespace std;

int Student::nextStudentID = 1000;

Student::Student() : Person() {
    Student_ID = nextStudentID;
    nextStudentID++;
    enrollment_date = Date();
}

Student::Student(string name, Date birth, Date e) : Person(name, birth) {
    Student_ID = nextStudentID;
    nextStudentID++;
    enrollment_date = e;
}

int Student::getStudent_ID() {
    return Student_ID;
}

Date Student::getEnrollment_date() {
    return enrollment_date;
}

void Student::setStudent_ID(int s) {
    Student_ID = s;
}

void Student::setEnrollment_date(Date d) {
    enrollment_date = d;
}

int Student::getid() {
    return Student_ID;
}

bool Student::isGraduateStudent() {
    return false;
}

void Student::print() {
    Person::print();

    cout << "Student ID: " << Student_ID << endl;

    cout << "Enrollment date: ";
    enrollment_date.print();
    cout << endl;
}

Student::~Student() {
    cout << "Student object deleted." << endl;
}
