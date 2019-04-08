#ifndef MONITOR_H
#define MONITOR_H

#include <vector>

#include "Student.h"

class Monitor
{
    public:
        virtual void update(Student*) = 0;
        void printLogs() {
            cout << "LOGS:" << endl;
            for(auto i = logs.begin(); i != logs.end(); ++i) {
                cout << *i << endl;
            }
        };
    protected:
        vector<string> logs;
};

#endif