#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "View.h"

void View::mainMenu(int &selection)
{
  int numOptions = 1;

  cout << endl;
  cout << "(1) Add student" << endl;
  cout << "(0) Exit" << endl;

  while (selection < 0 || selection > numOptions) {
    cout << "Enter your selection: ";
    cin  >> selection;
  }
}

void View::readID(int &stuId)
{
    cout << "student id:   ";
    cin  >> stuId;
}

void View::courseInfo(int &courseCode, int &grade, int &term, string &instructor)
{
    cout << "course code <0 to end>:  ";
    cin  >> courseCode;
    if (courseCode == 0) {
        return;
    }
    cout << "grade:                   ";
    cin  >> grade;

    cout << "term code:               ";
    cin >> term;

    cout << "Instructor:              ";
    cin >> instructor;
}

void View::print(Storage &data)
{
    cout << endl << endl << "STUDENT INFO: " << endl;
    data.print();
    cout << endl;
}