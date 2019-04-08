#ifndef STORAGE_H
#define STORAGE_H

#include "Student.h"
#include "defs.h"

class Storage
{
    public:
        Storage();
        ~Storage();
        void addStu(Student*&);
        void print();
        Storage& operator+=(Student*&);

    private:
        Student* students[MAX_NUM_STU];
        int numStudents;
};

#endif
