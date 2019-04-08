#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include "CourseList.h"

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
    Student& operator+=(Course*&);

  private:
    CourseList* courses;
    int    id;
};

#endif
