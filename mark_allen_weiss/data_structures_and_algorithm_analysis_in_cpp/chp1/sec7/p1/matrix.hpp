#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
namespace matrix {
template<typename object>
class matrix{
public:
    matrix(int rows, int cols) : array(rows) 
    // initialization list for array, get a  std::vector{ rows * std::vector<object>} 
    {  //here we can only use () instead of {}
        std::cout << "2-parameters ctor" << std::endl;
        for (auto & thisRow : array)
        {
            thisRow.resize(cols); // to make each row a std::vector<Object> of size cols
        }
    }

    matrix( std::vector<std::vector<object>> v) : array{v}
    {
        std::cout << "copy ctor" << std::endl;
    } // copy ctor

    matrix(std::vector<std::vector<object>>&& v) : array{std::move(v)}
    {
        std::cout << "move ctor" << std::endl;
    }
    std::size_t numrows() const {
        return array.size();
    }

    std::size_t numcols() const {
        return numrows() ? array[0].size() : 0;
    }
private:
    std::vector<std::vector<object>> array;
};

}
#endif
