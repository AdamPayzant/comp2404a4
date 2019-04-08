#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"

Course::Course(int c, int g, int t, string p)
{
  code  = c;
  grade = g;
  term = t;
  instructor = p;
}

void Course::print()
{
  string str;

  cout << "-- COMP " << code << ":  ";
  cout << right << setw(2) << grade   << "  ";
  getGradeStr(str);
  cout << left << setw(3) << str << "  ";
  cout << setw(6) << term << "  ";
  cout << instructor << endl;

}

void Course::getGradeStr(string& gradeStr)
{
  string gradeStrings[] = {
    "WDN", "F", "D-", "D", "D+", "C-", "C", "C+", 
    "B-", "B", "B+", "A-", "A", "A+" };

  if ( grade >= -1 && grade <= 12 )
    gradeStr = gradeStrings[grade+1];
  else
    gradeStr = "Unknown";
}

bool Course::lessThan(Course *&compare)
{
  if(compare->code > code) {
    return(true);
  }
  else if (compare->code < code){
    return(false);
  }
  else {
    if(compare->term > term) {
      return(true);
    }
    else {
      return(false);
    }
  }
}

void Course::getGrade(int &g)
{
  g = grade;
}