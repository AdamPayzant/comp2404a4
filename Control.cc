using namespace std;

#include "Control.h"

Control::Control()
{
    monitors.push_back(new GPAMonitor(3.0));
    monitors.push_back(new FWMonitor(2));
    vector<string> studentInfo;
    server.retrieve(studentInfo);
    for(int i=0; i<studentInfo.size(); ++i) {
      stringstream ss;
      string stuData = studentInfo[i];
      int id;
      Student* stu;
      ss.str(stuData);
      ss >> id;
      stu = new Student(id);
      stuData=stuData.substr(stuData.find_first_of(" \t")+1);
      while(1) {
        if(stuData.substr(0, 2) == "0") {
          break;
        }
        ss.clear();
        ss.str(stuData);
        int courseCode, grade, term;
        string instructor;

        ss >> courseCode >> term >> grade >> instructor;
        stu->addCourse(new Course(courseCode, grade, term, instructor));

        stuData=stuData.substr(stuData.find_first_of(" \t")+1);
        stuData=stuData.substr(stuData.find_first_of(" \t")+1);
        stuData=stuData.substr(stuData.find_first_of(" \t")+1);
        stuData=stuData.substr(stuData.find_first_of(" \t")+1);
      }
      data += stu;
      notify(stu);
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
