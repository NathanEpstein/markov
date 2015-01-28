all: libmarkov.a

markov.o: markov.cpp
	g++ -c markov.cpp

libmarkov.a: markov.o
	ar -rcs libmarkov.a markov.o