#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "CourseList.h"

float CourseList::computeGPA()
{
    Node* current = head;
    float gpa = 0;
    int len = 0;
    while(current != NULL) {
        int grade;
        current->data->getGrade(grade);
        if(grade != -1) {
            gpa += (float)grade;
            len++;
            current = current->next;
        }
    }
    if(gpa > 0) {
        gpa = gpa/(float)len;
    }
    return gpa;
}

int CourseList::computeNumFW()
{
    int numFW = 0;
    Node* current = head;
    while(current != NULL) {
        int grade;
        current->data->getGrade(grade);
        if(grade < 1) {
            numFW++;
        }
        current = current->next;
    }
    cout << "Num FW: " << numFW;
    return numFW;
}
