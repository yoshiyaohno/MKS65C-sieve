#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//// SOME OPTIMIZATIONS ////
// array size:
//      1.15 * n log n          n > 5000
//      1.3  * n log n + 10     otherwise
//
// 1. Stop early (sqrt n)
// 2. Don't store even values
// 3. minimise writes, short circuit, etc
//      ex. CHEKC 1 BeFORE WRITING
// 4. b i t w i s e    o p e r a t i o n s
//
//// SOME OPTIMIZATIONS ////

int sieve( int n )
{
    int size;
    if( n < 5000 )
        size = 1.3 * n * log(n) + 10;
    else
        size = 1.15 * n * log(n);

    printf("\t\tSIZE %d\n", size);
    char jeff[size];
    int i = size;
    while(i--) jeff[i] = 0;

    char *p;
    int tracer = 1;

    // printf("PRE-SIEV\tn is %d\n", n);

    while( tracer < sqrt(size) ) {
        while( jeff[++tracer] );
        // printf("TRACER: %d\n", tracer);
        p = jeff + tracer;
        while( (p += tracer) < jeff + size ) {
            printf("%p\n", p);
            *p = 1;
        }
        // printf("IN-SIEV\tn is %d\n", n);
    }


    // // printing
    // p = jeff;
    // while( p < jeff + sizeof(jeff) )
    //     printf("%x,", *p++);
    // printf("\n");
    // // printing

    int oof = 1;
    i = n;
    while(i) {
        // printf("POSTSIEV\tn is %d\n", n);
        while( jeff[ ++oof] );
        i--;
    }
    printf("n=%d: %d\n", n, oof);

}

int main()
{
    int i;
    sieve(10000);
    //sieve(551128);
    //sieve(551129);
    //sieve(600000);
    return 0;
}
