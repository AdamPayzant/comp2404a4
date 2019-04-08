#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Storage.h"

Storage::Storage() 
{
    numStudents = 0;
}

Storage::~Storage()
{
    int i;
    for(i = 0; i < numStudents; i++) {
        delete students[i];
    }
}

void Storage::addStu(Student *&student)
{
    students[numStudents] = student;
    numStudents++;
}

void Storage::print() 
{
    int i;
    for(i = 0; i < numStudents; i++) {
        students[i]->print();
    }
}