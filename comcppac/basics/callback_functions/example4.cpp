/**
 * @file example4.cpp
 * @author peng.sun
 * @brief use polymorphism and virtual function to replace function pointer
 * @version 0.1
 * @date 2022-12-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdlib>

using namespace std;


class Sorter
{
    public:
    static int compare (const void* first_arg, const void* second_arg)
    {
        int first = *(int*)first_arg;
        int second = *(int*)second_arg;
        if (first < second)
        {
            return 1;
        }
        else if (first == second)
        {
            return 0;
        }
        else 
        {
            return -1;
        }
    }
};

// cpp_qsort, a qsort using C++ features like virtual functions
//void qsort(void *base, size_t nmemb, size_t size, Sorter *compar);

class AscendingSorter : public Sorter 
{
    public:
    static int compare (const void* first_arg, const void* second_arg)
    {
        int first = *(int*)first_arg;
        int second = *(int*)second_arg;
        if (first < second)
        {
            return -1;
        }
        else if (first == second)
        {
            return 0;
        }
        else 
        {
            return 1;
        }
    }


};

int main()
{
    int array[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        array[i] = 10 - i;
    }
    AscendingSorter* AS = new AscendingSorter();
    Sorter* S = new Sorter();
    qsort(array, 10, sizeof(int), S->compare);
    for (i = 0; i < 10; i++){
        cout << array[i] << endl;
    }
    return 0;
}
