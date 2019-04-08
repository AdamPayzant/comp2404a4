#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "FWMonitor.h"

/*
Constructor setting maximum number of fails or withdrawls allowed before alert
*/
FWMonitor::FWMonitor(int thresh)
{
    fwThresh = thresh;
}

/*
Checks if new student has failed or withdrawn too many classes
Adds them to the logs if they have
*/
void FWMonitor::update(Student* stu)
{
    int numFW = stu->computeNumFW();
    if(numFW > fwThresh) {
        logs.push_back("Id: " + to_string(stu->getID()) + "  Num FW: " + to_string(numFW));
    }
}