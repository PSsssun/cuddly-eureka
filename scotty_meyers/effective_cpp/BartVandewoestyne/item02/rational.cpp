/**
 * @file rational.cpp
 * @author peng.sun
 * @brief 
 * @version 0.1
 * @date 2022-12-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

class Rational {

public:
    Rational(int numerator = 0, int denominator = 1);
    int get_n() const 
    {
        return n;
    }
    int get_d() const
    {
        return d;
    }

private:
    int n, d; // numerator and denominator

friend ostream& operator<<(ostream& s, const Rational& r);
};

Rational::Rational(int numerator, int denominator)
    : n(numerator), d(denominator)
{}

//it leads to redefinition
// ostream& operator<<(ostream& s, const Rational& r)
// {
//     s << r.get_n() << "//" << r.get_d() << endl;
//     return s;
// }

ostream& operator<<(ostream& s, const Rational& r) // const non-member function cannot have 'const' qualifier
{
    s << r.n << '/' << r.d;
    return s;
}

int main()
{
    Rational r(3, 4);
    std::cout << r << std::endl;
}