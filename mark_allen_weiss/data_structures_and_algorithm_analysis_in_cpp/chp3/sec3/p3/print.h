#pragma once
#include <iostream>
template<typename Container>
auto begin(Container & c) -> decltype(c.begin())
{
    return c.begin();

}


template<typename Container>
auto begin(const Container & c) -> decltype(c.begin())
{
    return c.begin();
}












template <typename Container>
void print(const Container& c, std::ostream& out = std::cout){
    if (c.empty())
        out << "(empty)";
    else
    {
        auto itr = begin(c);

        out << "[ " << *iter++;

        while (itr!= end(c))
            out << ", " << *itr++;

       out << " ]" << endl; 
    
    }

}
