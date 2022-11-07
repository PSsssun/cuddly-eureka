#pragma once

template <typename Container, typename Object>
void change(Container & c, const Object & newValue)
{
    typename Container::iterator itr = c.begin();
    while(itr != c.end())
        *itr++ = newValue;

}

