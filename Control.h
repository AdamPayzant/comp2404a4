#ifndef CONTROL_H
#define CONTROL_H

#include <vector>

#include "Storage.h"
#include "Student.h"
#include "View.h"
#include "Monitor.cc"
#include "FWMonitor.h"
#include "GPAMonitor.h"
#include "StuServer.h"

class Control
{
    public:
        Control();
        ~Control();
        void Launch();
    private:
        Storage data;
        StuServer server;
        View io;
        vector<Monitor*> monitors;
        void notify(Student* newStu);
};

#endif