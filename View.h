#ifndef VIEW_H
#define VIEW_H

#include "Student.h"
#include "Storage.h"
#include "Course.h"

class View
{
    public:
        void mainMenu(int&);
        void readID(int&);
        void courseInfo(int&, int&, int&, string&);
        void print(Storage&);
};

#endif