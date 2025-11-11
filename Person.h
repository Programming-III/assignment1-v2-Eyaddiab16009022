#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person();
    Person(const string& name, int id);
    virtual ~Person();
    virtual void displayInfo() const;
};
#endif
