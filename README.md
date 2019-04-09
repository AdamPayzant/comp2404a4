Comp2404 Assignment 4 v 1

Developed by Edward Adam Payzant with code provided by Christine Laurendeau

Creates a student auditing output with provided classes, marks, term taken, and instructor

**Now with "Cloud" Support**

1. Included Files
  - Course.cc, Course.h
  - StuServer.h, StuServer.o
  - CourseList.cc, CourseList.h
  - List.cc, List.h
  - Student.cc, Student.h
  - Storage.cc, Storage.h
  - View.cc, View.h
  - Monitor.h
  - FWMonitor.cc, FWMonitor.h
  - GPAMonitor.cc, GPAMonitor.h
  - Control.cc, Control.h
  - Main.cc
  - defs.h
  - Makefile
  - in.txt
  - README.md

2. Compilation Instructions
  - Requires gcc and gmake
  - Inside a terminal, navigate to the project directory, then run the Makefile
  - ex) "make"

3. Launching
  - To run as is, in a terminal input "./sas"
  - To run with desired input text file, in a terminal input "./sas < [Desired .txt file]"
  - ex) "./sas < in.txt"

4. Operating
  - Inside program, following input prompts to input your information

5. Notes
  - Assuming StuServer.o is unchanged, program should start with students already added
  - in1.txt is optimal for testing a cases of input
