CC=g++
CCFLAGS=-c

all: calccalc

calccalc: main.o FourFuncString.o Solution.o
	$(CC) *.o -o calccalc.exe

main.o: ../src/main.cpp
	$(CC) $(CCFLAGS) ../src/main.cpp

FourFuncString.o: ../src/fourfunc/cpps/FourFuncString.cpp
	$(CC) $(CCFLAGS) ../src/fourfunc/cpps/FourFuncString.cpp

Solution.o: ../src/common/classes/cpp/Solution.cpp
	$(CC) $(CCFLAGS) ../src/common/classes/cpp/Solution.cpp