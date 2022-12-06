#include <stdlib.h>
#include <stdio.h>

int int_sorter(const void *first_arg, const void * second_arg)
{
    int first = *(int*) first_arg; // convert to (int*) then get value the pointer points to
    int second = *(int*) second_arg;
    if (first < second)
    {
        return -1; // first_arg, second_arg
    }
    else if (first == second)
    {
        return 0; //
    }
    else 
    {
        return 1; // second_arg , first_arg
    }

}
int main()
{
    int array[10];
    int i;
    /* fill array*/
    for (i = 0; i< 10; ++i)
    {
        array[i] = 10 - i;
    }
    qsort(array, 10, sizeof(int), int_sorter);
    for (i = 0; i < 10; ++i)
    {
        printf( "%d\n" ,array[ i ] );
    }
    return 0;
}