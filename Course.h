#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"
using namespace std;

#include "person.h"

class Student : public Person {
private:
    int yearLevel;
    string major;
public:
    Student();
    Student(const string& name, int id, int yearLevel, const string& major);
    virtual ~Student();
    virtual void displayInfo() const override;
};

#endif
