#include "template_remove.h"
#include <vector>
#include <iterator>
#include <chrono>
#include <iostream>


int main(){

    std::vector<int> v1;
    int size1 = 800000;
    int size2 = 1600000;
    for (int i = 0; i < size1; i++){
        v1.push_back(i);
    }

    std::vector<int> v2;
    for (int i = 0; i < size2; i++){
        v2.push_back(i);
    }
    auto start1 = std::chrono::high_resolution_clock::now();
    
    removeEveryOtherItem<std::vector<int>>(v1);

    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    removeEveryOtherItem<std::vector<int>>(v2);
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);


    std::cout << "it takes " << duration1.count()  << " microseconds to remove " << size1 << " items of list" << std::endl;
     std::cout << "it takes " << duration2.count()  << " microseconds to remove " << size2 << " items of list" << std::endl;








}
