# For more info: Makefile habr

all: main


main: sq_equation.o main.o
	g++ main.o sq_equation.o -o main -lm
	
test: sq_equation.o test.o
	g++ test.o sq_equation.o -o test -lm
	./test

sq_equation.o: sq_equation.cpp
	g++ -c -o sq_equation.o sq_equation.cpp

test.o: test.cpp
	g++ -c -o test.o test.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm *.o