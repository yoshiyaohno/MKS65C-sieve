all : sieve.o
	gcc -o sieve sieve.o -lm

sieve.o : sieve.c
	gcc -c sieve.c -lm

run : 
	./sieve

clean :
	rm sieve *.o

debug :
	gcc -g -c sieve.c -lm
	gcc -g -o sieve sieve.o -lm
