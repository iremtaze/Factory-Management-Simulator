all: main

main: main.o factory.o worker.o machine.o headworker.o simulation.o unit.o
	g++ -std=c++17 -o main main.o factory.o worker.o machine.o headworker.o simulation.o unit.o

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

factory.o: factory.cpp
	g++ -std=c++17 -c factory.cpp

worker.o: worker.cpp
	g++ -std=c++17 -c worker.cpp

machine.o: machine.cpp
	g++ -std=c++17 -c machine.cpp

headworker.o: headworker.cpp
	g++ -std=c++17 -c headworker.cpp

simulation.o: simulation.cpp
	g++ -std=c++17 -c simulation.cpp

unit.o: unit.cpp
	g++ -std=c++17 -c unit.cpp

clean:
	rm -f *.o main
