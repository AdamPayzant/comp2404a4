#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "GPAMonitor.h"

/*
Constructor setting minumum GPA
*/
GPAMonitor::GPAMonitor(float min)
{
    minGPA = min;
}

/*
Checks if new student's GPA is below the minimum GPA.
If it is, it adds to the logs (hopefully)
*/
void GPAMonitor::update(Student* stu)
{
    float gpa = stu->computeGPA();
    if(gpa < minGPA) {
        logs.push_back("Id: " + to_string(stu->getID()) + "   GPA: " + to_string(gpa));
        //logs.push_back("Id: " + stu->getID() + "   GPA: " + gpa);
    }
}