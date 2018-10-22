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

    int size_sqrt = sqrt(size);
    while( tracer < size_sqrt ) {
        while( jeff[++tracer] );
        n--;
        // printf("TRACER: %d\n", tracer);
        p = jeff + tracer;
        while( (p += 2*tracer+3) < jeff + size )
            *p = 1;
        // printf("IN-SIEV\tn is %d\n", n);
    }

    while(--n)
        while( jeff[ ++tracer] );
    return 2*tracer+3;
}

// int main()
// {
//     int n;
//     for( n = 1000000; n < 1000011; ++n )
//         printf("n=%d: %d\n", n, sieve(n) );
//     return 0;
// }
