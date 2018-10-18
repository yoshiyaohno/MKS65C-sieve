#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

//// SOME OPTIMIZATIONS ////
//
//    still to do
// 3. minimise writes, short circuit, etc
// 4. b i t w i s e    o p e r a t i o n s
// 5. see if you can find a way around calloc
//      (multiple varaibles? lol)
//
//// SOME OPTIMIZATIONS ////

int sieve( int n )
{
    if(n==0) return 2;
    if(n==1) return 3;

    int size;
    if( n < 5000 )
        size = (1.3 * n * log(n) + 10) / 2;
    else
        size = 1.15 * n * log(n) / 2;

    // printf("\t\tSIZE %d\n", size);
    char *jeff = calloc( size, 1);

    char *p;
    int tracer = 0;

    // printf("PRE-SIEV\tn is %d\n", n);

    int prime = 0;

    int size_sqrt = sqrt(size);
    while( tracer < size_sqrt ) {
        while( jeff[++tracer] );
        n--;
        prime = tracer;
        // printf("TRACER: %d\n", tracer);
        p = jeff + tracer;
        while( (p += (2*tracer+1)) < jeff + size )
            *p = 1;
        // printf("IN-SIEV\tn is %d\n", n);
    }

    while(n--)
        while( jeff[ ++prime] );
    return 2*prime+1;
}

// int main()
// {
//     int n;
//     for( n = 1000000; n < 1000011; ++n )
//         printf("n=%d: %d\n", n, sieve(n) );
//     return 0;
// }
