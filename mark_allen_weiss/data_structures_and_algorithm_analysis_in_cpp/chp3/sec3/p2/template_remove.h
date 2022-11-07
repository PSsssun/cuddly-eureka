#pragma once


template <typename Container>
void removeEveryOtherItem(Container & lst)
{
    auto itr = lst.begin(); // itr is a Container::iterator

    while (itr != lst.end())
    {
        itr = lst.erase(itr);
        if (itr != lst.end())
            ++itr;
    
    }

}



