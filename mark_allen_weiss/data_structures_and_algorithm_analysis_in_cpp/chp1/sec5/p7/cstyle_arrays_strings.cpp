#include <iostream>
#include <string.h>
int main()
{
    std::cout << "c_style arrays and strings" << std::endl;
    int arr1[10]={1, 2, 3};
    
    int n = 10;
    int *arr2 = new int[n];
    delete [] arr2;

    const int* arr3 = arr1;
   
    std::cout << arr3[0] << std::endl;  

    {
        char src[40];
        char dest[100];

        memset(dest, '\0', sizeof(dest));
        std::cout << dest[0] << "hi" << dest[10] << "cpp" << std::endl;
        strcpy(src, "hello cpp");
        strcpy(dest, src);

        std::cout << src << std::endl;
        std::cout << dest << std::endl;
        
    
    }
    
    
    return 0;

}
