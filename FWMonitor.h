#ifndef FWMONITOR_H
#define FWMONITOR_H

#include <vector>

#include "Monitor.cc"
#include "Student.h"

class FWMonitor: public Monitor
{
    public:
        FWMonitor(int);
        void update(Student*);
    protected:
        int fwThresh;
};

#endif