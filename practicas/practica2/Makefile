all:
	gcc main.c operations.c -o operations.exe
	./operations.exe

main.o: main.c
	gcc -c main.c

operations.o: operations.c
	gcc -c operations.c

test:
	gcc main.c operations.c -o operations.exe
	./maintest.tcl ./operations.exe
