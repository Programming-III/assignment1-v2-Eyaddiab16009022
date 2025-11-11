#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
#using namespace std;
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
