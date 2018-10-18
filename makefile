all : sieve.o driver.o
	gcc -o sieve sieve.o driver.o -lm

sieve.o : sieve.c sieve.h
	gcc -c sieve.c -lm

driver.o : driver.c sieve.h
	gcc -c driver.c

run : 
	./sieve $(args)

clean :
	rm sieve *.o

debug :
	gcc -g -c sieve.c -lm
	gcc -g -c driver.c
	gcc -g -o sieve_debug sieve.o driver.o -lm
