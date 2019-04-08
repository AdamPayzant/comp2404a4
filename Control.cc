#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Control.h"

Control::Control()
{
    monitors.push_back(new GPAMonitor(3.0));
    monitors.push_back(new FWMonitor(2));
    vector<string> studentInfo;
    server.retrieve(studentInfo);
    for(auto student = studentInfo.begin(); student != studentInfo.end(); ++student) {

    }
}

Control::~Control()
{
    for(auto monitor = monitors.begin(); monitor != monitors.end(); ++monitor) {
        (*monitor)->printLogs();
        delete *monitor;
    }
    monitors.clear();
}

void Control::Launch()
{
    while(1) {
        int menuSelection = -1;
        io.mainMenu(menuSelection);

        if (menuSelection == 0) {
            break;
        }

        else if(menuSelection == 1) {
            Student* stu;
            int stuID;
            Course toAdd;

            io.readID(stuID);
            stu = new Student(stuID);
            while(1) {
                int     courseCode, grade, term;
                string  instructor;
                io.courseInfo(courseCode, grade, term, instructor);
                if(courseCode == 0) {
                    break;
                }
                stu->addCourse(new Course(courseCode, grade, term, instructor));
            }
            //io.courseInfo(stu);
            data.addStu(stu);
            notify(stu);
        }
    }
    io.print(data);
}

void Control::notify(Student* newStu)
{
    for(auto monitor = monitors.begin(); monitor != monitors.end(); ++monitor) {
        (*monitor)->update(newStu);
    }
}
