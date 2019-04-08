#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Student.h"

Student::Student(int i)
{
  id = i;
  courses = new CourseList();
}

Student::~Student() {
  delete courses;
}

void Student::print()
{
  cout<< endl << "Id: " << id << "   GPA: " << computeGPA() << endl;
  courses->print();
}

void Student::addCourse(Course *c)
{
  courses->add(c);
}

float Student::computeGPA()
{
  return(courses->computeGPA());
}

int Student::computeNumFW()
{
  return(courses->computeNumFW());
}

int Student::getID()
{
  return(id);
}

Student& Student::operator+=(Course*& adder)
{
  this->addCourse(adder);
  return *this;
}
