#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

//////// THIS ONE IS BITWISE ////////

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
    char p_offset = 0;
    int tracer = 0;
    char *trace_ptr = jeff;
    char trace_offset = 0;


    // printf("PRE-SIEV\tn is %d\n", n);

    int size_sqrt = sqrt(size * 8);
    while( tracer < size_sqrt ) {
        while( jeff[(++tracer) >> 3] & 1<<(tracer & 0b111) );
        n--;
        p = jeff + (2*tracer+1>>3);
        p_offset = 2*tracer+1 & 0b111;
        printf("TRACER: %d\np-jeff %ld\noffset %d\n\n", tracer, p - jeff, p_offset);
        while( (p += (2*tracer+1)>>3) < jeff + size * 8 ) {
            p_offset += ((2*tracer+1) & 0b111);
            if( p_offset > 7 ) {
                p_offset -= 8;
                ++p;
            }
            *p |= 1<<p_offset;
        }
        // printf("IN-SIEV\tn is %d\n", n);
    }

    while(--n)
        while( jeff[ (++tracer) >> 3] & 1<<(tracer & 0b111) );
    return 2*tracer+1;
}

// int main()
// {
//     int n;
//     for( n = 1000000; n < 1000011; ++n )
//         printf("n=%d: %d\n", n, sieve(n) );
//     return 0;
// }
