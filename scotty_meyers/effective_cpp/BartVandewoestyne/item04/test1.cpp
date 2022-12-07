#include <stdio.h>
#define evil( x) printf( "hello "); // hi there, \
                 printf( "%s\n", x); // you!



int main( int argc, char** argv)
{
    evil( "bastard");
                            //----------------/
    printf( "hello ");      // Hey, what the??/
    printf( "%s\n", "you"); // heck??         /
                            //----------------/

    return 0;
}