#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"
using namespace std;
#include <string>
class Instructor : public Person {
private:
    string department;
    int experienceYears;
public:
    Instructor();
    Instructor(const string& name, int id, const string& department, int experienceYears);
    virtual ~Instructor();
    virtual void displayInfo() const override;
};


#endif
