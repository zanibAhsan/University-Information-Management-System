#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

Course::Course() {
    Department = "";
    Course_number = 0;
    Course_name = "";
    Professor_name = "";
}

Course::Course(string d, int c, string n, string p) {
    Department = d;
    Course_number = c;
    Course_name = n;
    Professor_name = p;
}

string Course::getDepartment() {
    return Department;
}

int Course::getCourse_number() {
    return Course_number;
}

string Course::getCourse_name() {
    return Course_name;
}

string Course::getProfessor_name() {
    return Professor_name;
}

void Course::setDepartment(string d) {
    Department = d;
}

void Course::setCourse_number(int c) {
    Course_number = c;
}

void Course::setCourse_name(string n) {
    Course_name = n;
}

void Course::setProfessor_name(string p) {
    Professor_name = p;
}

void Course::print() {
    cout << "Department: " << Department << endl;
    cout << "Course number: " << Course_number << endl;
    cout << "Course name: " << Course_name << endl;
    cout << "Professor name: " << Professor_name << endl;
}

Course::~Course() {
    cout << "Course object deleted." << endl;
}
