#ifndef COURSE_H
#define COURSE_H

class Course
{
  public:
    Course(int=0, int=0, int=201910, string="");
    void print();
    bool lessThan(Course*&);
    void getGrade(int&);

  private:
    int code;	// course code, for example 2404 for COMP2404
    int grade;	// numeric grade from 0 (F) to 12 (A+), with -1 for WDN
    int term; // the term the class is taken in
    string instructor; // the instructor of the course
    void getGradeStr(string&);
};

#endif
