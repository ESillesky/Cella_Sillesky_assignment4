all: main

main: main.o BinaryTree.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o main main.o BinaryTree.o

main.o: BinaryTree.h main.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c main.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c BinaryTree.cpp

clean:
	rm -rf main
	rm -rf *.o
