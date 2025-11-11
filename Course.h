#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "student.h"
#include "instructor.h"
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
    Instructor instructor;
public:
    Course();
    Course(const string& courseCode, const string& courseName, int maxStudents, const Instructor& instructor);
    ~Course();
    bool addStudent(const Student& s);
    void displayCourseInfo() const;
};

#endif
