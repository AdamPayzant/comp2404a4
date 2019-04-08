#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include "List.h"

class Student
{
  public:
    Student(int=0);
    ~Student();
    void print();
    void addCourse(Course*);
    float computeGPA();
    int computeNumFW();
    int getID();

  private:
    List* courses;
    int    id;
};

#endif
