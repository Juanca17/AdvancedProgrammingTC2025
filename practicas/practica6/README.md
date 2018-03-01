
# practica06

# How to compile
make run

# How to run test
make test

# How to debug the program
gcc -g name_of_file.c -o name_of_file
gdb name_of_file

## How to start the Program
break main
run # Execute the program
next # Next Line
print &i # Print the address of the variable
print sizeof(int) # Print sizeof the int type
x/4xb &i # Get the raw bytes of i. I want to examinate 4 values formatted as hex numerals. byte by byte
ptype i # Tell me the type of c expression
x/12xb &a # a is an array

# Linking stuff and generating the program

If you have modules you have to compile one by one
gcc -c module1.c # This command generates module1.o
gcc -c program-that-depends-of-module1.c
gcc -o program.out module1.o program-that-depends-of-module1.o
./program.out

# What is a hash?
A data structure that is built with nodes which are made with C structs. These nodes link a key to a piece of data (or several if a collision is made). In order to link this key, a hash algorithm is needed; this algorithm needs to arrange within its memory the data's elements.

# How it works
The program's files are:
- hash.h: It declares the structs necessary in order to build the hash.
- hash.c: it is the implementation of the hash itself.
- hashtest.c: It creates tests with predetermined values in order to prove the functions init and insert.
- main.c: It gathers all of these information and looks for execution.
