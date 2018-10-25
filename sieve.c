/* SIEVE OF ERATOSTHENES */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

int sieve( int n )
{
    n -= 2; // ha ha
    unsigned int size;
    if( n < 5000 )
        size = (1.3 * n * log(n) + 10) / 2;
    else
        size = 1.15 * n * log(n) / 2;
    char *jeff = calloc( size/8, 1);
    unsigned int peff;
    unsigned int tracer = 0;
    char acc[] = {3, 2, 1, 2, 1, 2, 3, 1};
    unsigned int hrm = 0;
    int size_sqrt = sqrt(size);
    while( tracer < size_sqrt ) {
        while( jeff[(tracer += acc[hrm++ & 0b111])>>3] & 1<<(tracer&0b111) );
        n--;
        peff = tracer;
        while( (peff += (tracer<<1)+1) < size )
            jeff[ peff>>3 ] |= 1<<(peff&0b111);
    }
    while(--n)
        while( jeff[(tracer += acc[hrm++ & 0b111])>>3] & 1<<(tracer&0b111) );
    return (tracer<<1)+1;
}
