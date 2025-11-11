#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"


using namespace std;

// ==================== Person Class Implementation =========================
Person::Person() : name(""), id(0) {}
Person::Person(const string& name, int id) : name(name), id(id) {}
Person::~Person() {}
void Person::displayInfo() const {
    cout << "Name: " << name << " | ID: " << id << endl;
}
// ==================== Student Class Implementation ====================
Student::Student() : Person(), yearLevel(0), major("") {}
Student::Student(const string& name, int id, int yearLevel, const string& major)
    : Person(name, id), yearLevel(yearLevel), major(major) {
}
Student::~Student() {}
void Student::displayInfo() const {
    cout << "Student Name: " << name
        << " | ID: " << id
        << " | Year: " << yearLevel
        << " | Major: " << major << endl;
}
// ==================== Instructor Class Implementation ====================
Instructor::Instructor() : Person(), department(""), experienceYears(0) {}
Instructor::Instructor(const string& name, int id, const string& department, int experienceYears)
    : Person(name, id), department(department), experienceYears(experienceYears) {
}
Instructor::~Instructor() {}
void Instructor::displayInfo() const {
    cout << "Instructor Name: " << name
        << " | ID: " << id
        << " | Department: " << department
        << " | Experience (years): " << experienceYears << endl;
}
// ==================== Course Class Implementation ====================
Course::Course()
    : courseCode(""), courseName(""), maxStudents(0), students(nullptr), currentStudents(0), instructor() {
}

Course::Course(const string& courseCode, const string& courseName, int maxStudents, const Instructor& instructor)
    : courseCode(courseCode), courseName(courseName), maxStudents(maxStudents),
    students(nullptr), currentStudents(0), instructor(instructor) {
    if (maxStudents > 0) {
        students = new Student[maxStudents];
    }
}

Course::~Course() {
    delete[] students;
}

bool Course::addStudent(const Student& s) {
    if (currentStudents >= maxStudents || students == nullptr) {
        return false;
    }
    students[currentStudents] = s;
    currentStudents++;
    return true;
}

void Course::displayCourseInfo() const {
    cout << "Course Information" << endl;
    cout << "Course Code: " << courseCode << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Max Students: " << maxStudents << endl;
    cout << "Currently Enrolled: " << currentStudents << endl;
    cout << "Instructor Info:" << endl;
    instructor.displayInfo();
    cout << "Students Info:" << endl;
    for (int i = 0; i < currentStudents; i++) {
        students[i].displayInfo();
    }
}
// ==================== Main Function ====================
int main() {
    Instructor inst("Ahmed Ali", 1001, "Computer Science", 10);
    Course c("CS101", "Introduction to Programming", 3, inst);

    Student s1("Omar Nabil", 2202, 1, "CS");
    Student s2("Sara Mohamed", 2301, 1, "IT");

    c.addStudent(s1);
    c.addStudent(s2);

    c.displayCourseInfo();

    return 0;
}
