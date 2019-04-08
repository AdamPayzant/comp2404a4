#ifndef GPAMONITOR_H
#define GPAMONITOR_H

#include <vector>

#include "Monitor.cc"
#include "Student.h"

class GPAMonitor: public Monitor
{
    public:
        GPAMonitor(float);
        void update(Student*);
    protected:
        float minGPA;
};

#endif