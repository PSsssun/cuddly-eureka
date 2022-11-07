#include <list>
#include <iostream>
#include <iterator>

void print(const std::list<int>& lst, std::ostream & out = std::cout){
    typename std::list<int>::iterator itr = lst.begin();
    while (itr != lst.end())
    {
        std::out << *itr << std::endl;
        *itr = 0; // this is fishy!!!
        ++itr;
    }

}
