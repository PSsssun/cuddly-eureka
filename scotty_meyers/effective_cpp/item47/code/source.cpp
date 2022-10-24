#include <iostream>
#include <vector>

namespace ps {


    template<typename IterT, typename DistT>
        void DoAdvance(IterT& iter, DistT d, std::random_access_iterator_tag)
        {
            iter += d;
        }
    template<typename IterT, typename DistT>
        void DoAdvance(IterT& iter, DistT d, std::bidirectional_iterator_tag)
        {
            if (d >= 0) {while (d--) ++iter;}
            else {while(d++) --iter;}
        }
    template<typename IterT, typename DistT>
        void DoAdvance(IterT& iter, DistT d, std::input_iterator_tag)
        {
            if (d < 0) {
                throw std::out_of_range("Negative distance");
            }
            while (d--) ++iter;
        
        }

    template<typename IterT, typename DistT>
        void advance(IterT& iter, DistT d)
        {
            DoAdvance(
                iter, d,
                typename std::iterator_traits<IterT>::iterator_category()
                );
        }
}

int main() {
    std::cout << "Item 47: Use traits classes for information about types.\n";

    //vector container
    std::vector<int> vec;

    //initialising vector
    for (int i = 0; i < 10; i++)
        vec.push_back(i * 10);

    for (int i = 0; i < 10; i++) {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;

    //declaring the vector iterator
    std::vector<int>::iterator it = vec.begin();

    while (it < vec.end()) {
        std::cout << *it << " ";
        ps::advance<std::vector<int>::iterator, int>(it, 2);
    }

    return 0;

}
