all:
	g++ proyecto2.cpp -o proyecto2

test:
	g++ proyecto2.cpp -o proyecto2
	./sample.tcl ./proyecto2
	rm proyecto2

small:
	g++ proyecto2.cpp -o proyecto2
	./proyecto2 < B-small-practice.in 1> B-small.out
	rm proyecto2

large:
	g++ proyecto2.cpp -o proyecto2
	./proyecto2 < B-large-practice.in 1> B-large.out
	rm proyecto2

clear:
	rm B-small.out
	rm B-large.out
