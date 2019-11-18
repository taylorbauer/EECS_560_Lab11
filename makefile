Lab10: main.o Menu.o Node.o BinomialHeap.o BinomialTree.o
	g++ -std=c++11 main.o Menu.o Node.o BinomialHeap.o BinomialTree.o -o Lab10
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
BinomialTree.o: BinomialTree.cpp BinomialTree.h
	g++ -std=c++11 -c BinomialTree.cpp
BinomialHeap.o: BinomialHeap.cpp BinomialHeap.h
	g++ -std=c++11 -c BinomialHeap.cpp


clean:
	rm -f test *.o Lab10