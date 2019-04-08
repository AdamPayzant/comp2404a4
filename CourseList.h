#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"
#include "List.h"

class CourseList: public List<Course>
{
  public:
    float computeGPA();
    int computeNumFW();
};

#endif
