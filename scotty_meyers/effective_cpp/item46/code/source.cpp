#include <iostream>

template<typename T> class Rational;
template<typename T>
const Rational<T> DoMultiply(const Rational<T>& lhs, const Rational<T>& rhs);



template<typename T>
class Rational {
public:
    Rational(const T& numerator = 0,
             const T& denominator=1);
    const T numerator() const {return n_;}
    const T denominator() const {return d_;}

    friend const Rational<T> operator*(const Rational<T>& lhs,
                                       const Rational<T>& rhs)
    {
        return DoMultiply(lhs, rhs);
    }
private:
    T n_;
    T d_;
};

template<typename T>
const Rational<T> DoMultiply(const Rational<T>& lhs,
                             const Rational<T>& rhs)
{
    return Rational<T>(lhs.numerator() * rhs.numerator(),
                       lhs.denominator() * rhs.denominator());
}

template<typename T>
Rational<T>::Rational(const T& numerator, const T& denominator){
    n_ = numerator;
    d_ = denominator;
}

int main() {
    std::cout << "Item 46: Define non-member functions inside templates when type conversion." << std::endl;
    Rational<int> one_half(1, 2);
    Rational<int> result = one_half * 2;
    Rational<int> ans = result * 3.3;
    return 0;

}
