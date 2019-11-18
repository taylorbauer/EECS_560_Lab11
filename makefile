Lab11: main.o Menu.o Node.o DisjointSets.o
	g++ -std=c++11 main.o Menu.o Node.o DisjointSets.o -o Lab11
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
DisjointSets.o: DisjointSets.cpp DisjointSets.h
	g++ -std=c++11 -c DisjointSets.cpp


clean:
	rm -f test *.o Lab11