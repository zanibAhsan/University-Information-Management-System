#include "DataManager.h"
#include "Student.h"
#include "GraduateStudent.h"
#include "Professor.h"
#include "FullTimeProfessor.h"
#include "CourseRegistration.h"
#include "Course.h"
#include <iostream>
using namespace std;

DataManager::DataManager() {
    student_enrolled = 0;
    professor_count = 0;

    for (int i = 0; i < 5000; i++) {
        students[i] = nullptr;
    }

    for (int j = 0; j < 100; j++) {
        professors[j] = nullptr;
    }

    for (int k = 0; k < 200; k++) {
        courseregistrations[k] = nullptr;
    }
}

int DataManager::getstudent_enrolled() {
    return student_enrolled;
}

int DataManager::getprofessor_count() {
    return professor_count;
}

void DataManager::setStudent_enrolled(int s) {
    student_enrolled = s;
}

void DataManager::setProfessor_count(int p) {
    professor_count = p;
}

void DataManager::enrolled_student(Student* s) {
    for (int i = 0; i < 5000; i++) {
        if (students[i] == nullptr) {
            students[i] = s;
            student_enrolled++;
            cout << "Student enrolled successfully." << endl;
            return;
        }
    }

    cout << "Student cannot be enrolled." << endl;
}

void DataManager::addProfessor(Professor* p) {
    for (int i = 0; i < 100; i++) {
        if (professors[i] == nullptr) {
            professors[i] = p;
            professor_count++;
            cout << "Professor added successfully." << endl;
            return;
        }
    }

    cout << "Professor cannot be added." << endl;
}

void DataManager::removeStudent_fromUni(int Student_ID) {
    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr) {
            if (students[i]->getStudent_ID() == Student_ID) {
                for (int j = 0; j < 200; j++) {
                    if (courseregistrations[j] != nullptr) {
                        if (courseregistrations[j]->isStudentInCourse(Student_ID)) {
                            courseregistrations[j]->removeStudent(Student_ID);
                        }
                    }
                }

                delete students[i];
                students[i] = nullptr;
                student_enrolled--;

                cout << "Student removed from university." << endl;
                return;
            }
        }
    }

    cout << "Student not found." << endl;
}

void DataManager::addNewCourse(CourseRegistration* c) {
    for (int j = 0; j < 200; j++) {
        if (courseregistrations[j] == nullptr) {
            courseregistrations[j] = c;
            cout << "Course added successfully." << endl;
            return;
        }
    }

    cout << "Course cannot be added." << endl;
}

void DataManager::removeCourse(int Course_number) {
    for (int i = 0; i < 200; i++) {
        if (courseregistrations[i] != nullptr) {
            if (courseregistrations[i]->getCourse_number() == Course_number) {
                for (int j = 0; j < 5000; j++) {
                    if (students[j] != nullptr) {
                        if (students[j]->isCourseInStudent(Course_number)) {
                            students[j]->remove_course(Course_number);
                        }
                    }
                }

                delete courseregistrations[i];
                courseregistrations[i] = nullptr;

                cout << "Course removed from university." << endl;
                return;
            }
        }
    }

    cout << "Course was not removed." << endl;
}

void DataManager::registerStudentToCourse(int Student_ID, Course& course) {
    Student* foundStudent = nullptr;
    CourseRegistration* foundCourse = nullptr;

    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr && students[i]->getStudent_ID() == Student_ID) {
            foundStudent = students[i];
            break;
        }
    }

    if (foundStudent == nullptr) {
        cout << "Student was not found at the university." << endl;
        return;
    }

    for (int j = 0; j < 200; j++) {
        if (courseregistrations[j] != nullptr) {
            if (courseregistrations[j]->getCourse_number() == course.getCourse_number()) {
                foundCourse = courseregistrations[j];
                break;
            }
        }
    }

    if (foundCourse == nullptr) {
        cout << "Course was not found." << endl;
        return;
    }

    if (foundStudent->isCourseInStudent(foundCourse->getCourse_number())) {
        cout << "Student is already registered in this course." << endl;
        return;
    }

    int result1 = foundCourse->registerStudent(Student_ID);

    if (result1 == 1) {
        int result2 = foundStudent->add_course(foundCourse);

        if (result2 == 1) {
            cout << "Student has been registered to the course." << endl;
        }
        else {
            foundCourse->removeStudent(Student_ID);
        }
    }
}

void DataManager::dropCourse(int Student_ID, Course& course) {
    Student* foundStudent = nullptr;
    CourseRegistration* foundCourse = nullptr;

    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr && students[i]->getStudent_ID() == Student_ID) {
            foundStudent = students[i];
            break;
        }
    }

    if (foundStudent == nullptr) {
        cout << "Student was not found at the university." << endl;
        return;
    }

    for (int j = 0; j < 200; j++) {
        if (courseregistrations[j] != nullptr) {
            if (courseregistrations[j]->getCourse_number() == course.getCourse_number()) {
                foundCourse = courseregistrations[j];
                break;
            }
        }
    }

    if (foundCourse == nullptr) {
        cout << "Course was not found." << endl;
        return;
    }

    foundCourse->removeStudent(Student_ID);
    foundStudent->remove_course(course.getCourse_number());

    cout << "The course has been dropped." << endl;
}

bool DataManager::studentEnrolledInCourse(int Student_ID, Course& course) {
    for (int i = 0; i < 200; i++) {
        if (courseregistrations[i] != nullptr) {
            if (courseregistrations[i]->getCourse_number() == course.getCourse_number()) {
                return courseregistrations[i]->isStudentInCourse(Student_ID);
            }
        }
    }

    return false;
}

bool DataManager::studentEnrolledInUni(int Student_ID) {
    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr) {
            if (students[i]->getStudent_ID() == Student_ID) {
                return true;
            }
        }
    }

    return false;
}

void DataManager::addSupervisor(int professorID, int studentID) {
    Professor* foundProfessor = nullptr;
    GraduateStudent* foundStudent = nullptr;

    for (int i = 0; i < 100; i++) {
        if (professors[i] != nullptr && professors[i]->getid() == professorID) {
            foundProfessor = professors[i];
            break;
        }
    }

    if (foundProfessor == nullptr) {
        cout << "Professor was not found." << endl;
        return;
    }

    for (int j = 0; j < 5000; j++) {
        if (students[j] != nullptr && students[j]->getid() == studentID) {
            if (students[j]->isGraduateStudent()) {
                foundStudent = (GraduateStudent*)students[j];
            }
            break;
        }
    }

    if (foundStudent == nullptr) {
        cout << "Graduate student was not found." << endl;
        return;
    }

    foundProfessor->addGraduateStudent(foundStudent);
}

DataManager::~DataManager() {
    for (int i = 0; i < 5000; i++) {
        if (students[i] != nullptr) {
            delete students[i];
            students[i] = nullptr;
        }
    }

    for (int j = 0; j < 100; j++) {
        if (professors[j] != nullptr) {
            delete professors[j];
            professors[j] = nullptr;
        }
    }

    for (int k = 0; k < 200; k++) {
        if (courseregistrations[k] != nullptr) {
            delete courseregistrations[k];
            courseregistrations[k] = nullptr;
        }
    }

    cout << "DataManager object deleted." << endl;
}
