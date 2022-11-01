#include <iostream>
#include <vector>
#include <string>


void swap_by_copies(double & x, double & y)
{   

    std::cout << "swap_by_copies" << std::endl;
    double tmp = x;
    x = y;
    y = tmp;
}

void swap_by_copies(std::vector<std::string> & x, std::vector<std::string> & y)
{
    std::cout << "swap_by_copies for vector<string>: " << std::endl;
    std::vector<std::string> tmp = x;
    x = y;
    y = tmp;
}

void swap_by_cast(std::vector<std::string> & x, std::vector<std::string> & y)
{
    std::cout << "swap_by_cast: " << std::endl;
    std::vector<std::string> tmp = static_cast<std::vector<std::string> &&>(x);
    x = static_cast<std::vector<std::string> &&>(y);
    y = static_cast<std::vector<std::string> &&>(tmp);
}

void swap_by_move(std::vector<std::string> & x, std::vector<std::string> & y)
{
    std::cout << "swap_by_move: " << std::endl;
    std::vector<std::string> tmp = std::move(x);
    x = std::move(y);
    y = std::move(tmp);
}


int main()
{
    double x = 2.0;
    double y = 3.0;

    std::vector<std::string> a{"here", "we", "are"};
    std::vector<std::string> b{"where", "are", "you"};

    swap_by_copies(x, y);
    swap_by_copies(a, b);
    swap_by_cast(a, b);
    swap_by_move(a, b);

    return 0;
}
