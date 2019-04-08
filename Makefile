sas: main.o Control.o View.o Storage.o List.o Student.o Course.o GPAMonitor.o FWMonitor.o StuServer.o
	g++ -o sas main.o Control.o View.o Storage.o List.o Student.o Course.o GPAMonitor.o FWMonitor.o StuServer.o

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h View.h Student.h Storage.h Monitor.cc GPAMonitor.h FWMonitor.h StuServer.h
	g++ -c Control.cc

GPAMonitor.o: GPAMonitor.cc GPAMonitor.h Monitor.cc Student.h
	g++ -c GPAMonitor.cc

FWMonitor.o: FWMonitor.cc FWMonitor.h Monitor.cc Student.h
	g++ -c FWMonitor.cc

View.o: View.cc View.h Student.h Storage.h
	g++ -c View.cc

Storage.o: Storage.cc Storage.h Student.h
	g++ -c Storage.cc

Student.o: Student.cc Student.h List.h Course.h
	g++ -c Student.cc

CourseList.o: CourseList.cc CourseList.h List.h Course.h
	g++ -c CourseList.cc

List.o: List.cc List.h
	g++ -c List.cc

Course.o: Course.cc Course.h
	g++ -c Course.cc

clean:
	mv StuServer.o StuServer
	rm -f *.o sas
	mv StuServer StuServer.o
