all: markov.a

markov.o: markov.cpp
	gpp -c markov.cpp

libmarkov.a: markov.o
	ar -rcs libmarkov.a markov.o