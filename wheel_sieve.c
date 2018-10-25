#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

#define W_SIZE 8

//////// BITWISE ////////
// peff and tracer not pointers,
// looking at maybe 0.089

//// SOME OPTIMIZATIONS ////
//
//    still to do
// 5. see if you can find a way around calloc
//      (multiple varaibles? lol)
// 5.5? I guess make tracer a pointer, see if that helps
// 6. W H E E L    T I M E 
//
//// SOME OPTIMIZATIONS ////

int sieve( int n )
{
    n -= 2;
    int size;
    if( n < 5000 )
        size = (1.3 * n * log(n) + 10) / 2;
    else
        size = 1.15 * n * log(n) / 2;

    // printf("\t\tSIZE %d\n", size);
    char *jeff = calloc( size/8, 1);

    int peff;
    int tracer = 0;

    //int wheel[]   = {1, 7, 11, 13, 17, 19, 23, 29};
    int acc[]     = {3, 2, 1, 2, 1, 2, 3, 1};
    int hrm = 0;

    // printf("PRE-SIEV\tn is %d\n", n);


    int size_sqrt = sqrt(size);
    while( tracer < size_sqrt ) {
        while( jeff[(tracer += acc[hrm++%W_SIZE])/8] & 1<<(tracer%8) );
        n--;
        peff = tracer;

        while( (peff += 2*tracer+1) < size ) {
            jeff[ peff/8 ] |= 1<<(peff%8);
        }
    }

    while(--n)
        while( jeff[(tracer += acc[hrm++%W_SIZE])/8] & 1<<(tracer%8) );
    return 2*tracer+1;
}

// int main()
// {
//     int n;
//     for( n = 1000000; n < 1000011; ++n )
//         printf("n=%d: %d\n", n, sieve(n) );
//     return 0;
// }
