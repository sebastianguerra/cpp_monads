main: main.o maybe.o
	g++ main.o maybe.o

main.o:
	g++ -c main.cpp -o main.o

maybe.o:
	g++ -c maybe/maybe.cpp -o maybe.o
