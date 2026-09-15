#include <iostream>
#include "Date.h"
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "Professor.h"
#include "FullTimeProfessor.h"
#include "PartTimeProfessor.h"
#include "CourseRegistration.h"
#include "DataManager.h"

using namespace std;

int main() {
    cout << "University Information Management System" << endl;

    DataManager* manager = new DataManager();

    cout << "\nCreating Students:" << endl;
    UndergraduateStudent* student1 = new UndergraduateStudent("Ali Ahmad", Date(9, 15, 2003), Date(8, 25, 2025));
    GraduateStudent* student2 = new GraduateStudent("Sara Khan", Date(4, 20, 2001), Date(8, 25, 2025));
    UndergraduateStudent* student3 = new UndergraduateStudent("Omar Salem", Date(2, 10, 2004), Date(8, 25, 2025));

    manager->enrolled_student(student1);
    manager->enrolled_student(student2);
    manager->enrolled_student(student3);

    cout << "Students in system: " << manager->getstudent_enrolled() << endl;

    cout << "\nCreating Professors:" << endl;
    FullTimeProfessor* professor1 = new FullTimeProfessor("Dr. Nadia Smith", Date(5, 12, 1975), Date(8, 15, 2010));
    PartTimeProfessor* professor2 = new PartTimeProfessor("Dr. Mark Lee", Date(11, 3, 1980), Date(1, 10, 2022));

    manager->addProfessor(professor1);
    manager->addProfessor(professor2);

    cout << "Professors in system: " << manager->getprofessor_count() << endl;

    cout << "\nAdding Courses:" << endl;
    CourseRegistration* course1 = new CourseRegistration("COEN", 244, "Programming Methodology", professor1->getName(), 30);
    CourseRegistration* course2 = new CourseRegistration("MATH", 204, "Calculus", professor2->getName(), 25);
    CourseRegistration* course3 = new CourseRegistration("SOEN", 287, "Web Programming", professor1->getName(), 20);

    manager->addNewCourse(course1);
    manager->addNewCourse(course2);
    manager->addNewCourse(course3);

    cout << "\nAssigning Courses To Professors:" << endl;
    Professor* professorPointer;

    professorPointer = professor1;
    professorPointer->add_course(course1);
    professorPointer->add_course(course3);

    professorPointer = professor2;
    professorPointer->add_course(course2);

    cout << "\nRegistering Students To Courses:" << endl;
    manager->registerStudentToCourse(student1->getStudent_ID(), *course1);
    manager->registerStudentToCourse(student1->getStudent_ID(), *course2);
    manager->registerStudentToCourse(student2->getStudent_ID(), *course1);
    manager->registerStudentToCourse(student2->getStudent_ID(), *course3);
    manager->registerStudentToCourse(student3->getStudent_ID(), *course2);

    cout << "\nAdding Graduate Student Supervisor:" << endl;
    manager->addSupervisor(professor1->getEmployee_ID(), student2->getStudent_ID());

    cout << "\nShowing Polymorphism With Person Pointers:" << endl;
    Person* people[5];
    people[0] = student1;
    people[1] = student2;
    people[2] = student3;
    people[3] = professor1;
    people[4] = professor2;

    for (int i = 0; i < 5; i++) {
        cout << "\nObject ID from getid(): " << people[i]->getid() << endl;
        people[i]->print();
        cout << "------------------------------------------" << endl;
    }

    cout << "\nCurrent Course Statuses:" << endl;
    course1->print();
    cout << "\n------------------------------------------" << endl;
    course2->print();
    cout << "\n------------------------------------------" << endl;
    course3->print();
    cout << "\n------------------------------------------" << endl;

    cout << "\nChecking Course Registration:" << endl;
    if (manager->studentEnrolledInCourse(student1->getStudent_ID(), *course1)) {
        cout << "Verification: Student " << student1->getStudent_ID() << " is registered in COEN 244." << endl;
    }

    cout << "\nDropping Course:" << endl;
    manager->dropCourse(student1->getStudent_ID(), *course2);

    cout << "\nChecking University Enrollment:" << endl;
    if (manager->studentEnrolledInUni(student2->getStudent_ID())) {
        cout << "Student " << student2->getStudent_ID() << " is confirmed enrolled at the university." << endl;
    }

    cout << "\nRemoving Student From University:" << endl;
    manager->removeStudent_fromUni(student3->getStudent_ID());
    cout << "Students in system: " << manager->getstudent_enrolled() << endl;

    cout << "\nRemoving Course From University:" << endl;
    manager->removeCourse(course3->getCourse_number());

    cout << "\nCLEANING UP SYSTEM & DELETING DATA MANAGER:" << endl;
    delete manager;

    cout << "\nPROGRAM FINISHED:" << endl;
    return 0;
}
