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

    int peff;
    int tracer = 0;

    // printf("PRE-SIEV\tn is %d\n", n);

    int size_sqrt = sqrt(size * 8);
    while( tracer < size_sqrt ) {
        while( jeff[(++tracer)/8] & 1<<(tracer%8) );
        n--;
        // printf("TRACER: %d\n", tracer);
        peff = tracer;
        while( (peff += 2*tracer+1) < size * 8 )
            jeff[ peff/8 ] |= 1<<(peff%8);
        // printf("IN-SIEV\tn is %d\n", n);
    }

    while(--n)
        while( jeff[ (++tracer)/8] & 1<<(tracer%8) );
    return 2*tracer+1;
}

// int main()
// {
//     int n;
//     for( n = 1000000; n < 1000011; ++n )
//         printf("n=%d: %d\n", n, sieve(n) );
//     return 0;
// }
