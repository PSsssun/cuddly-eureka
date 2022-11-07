#include "template_remove.h"
#include <list>
#include <iterator>
#include <chrono>
#include <iostream>


int main(){

    std::list<int> list1;
    int size1 = 800000;
    int size2 = 1600000;
    for (int i = 0; i < size1; i++){
        list1.push_back(i);
    }

    std::list<int> list2;
    for (int i = 0; i < size2; i++){
        list2.push_back(i);
    }
    auto start1 = std::chrono::high_resolution_clock::now();
    
    removeEveryOtherItem<std::list<int>>(list1);

    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    removeEveryOtherItem<std::list<int>>(list2);
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);


    std::cout << "it takes " << duration1.count()  << " microseconds to remove " << size1 << " items of list" << std::endl;
     std::cout << "it takes " << duration2.count()  << " microseconds to remove " << size2 << " items of list" << std::endl;








}
