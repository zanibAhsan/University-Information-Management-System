#include "Person.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() {
    Name = "";
    Date_of_birth = Date();
}

Person::Person(string name, Date date_of_birth) {
    Name = name;
    Date_of_birth = date_of_birth;
}

string Person::getName() {
    return Name;
}

Date Person::getDate_of_birth() {
    return Date_of_birth;
}

void Person::setName(string name) {
    Name = name;
}

void Person::setDate_of_birth(Date date_of_birth) {
    Date_of_birth = date_of_birth;
}

void Person::print() {
    cout << "Name: " << Name << endl;
    cout << "Date of birth: ";
    Date_of_birth.print();
    cout << endl;
}

Person::~Person() {
    cout << "Person object deleted." << endl;
}
