#include<iostream>

class Rational {
public:
    Rational(int n = 0, int d = 1):n_(n),d_(d) {}
    ~Rational() {}
    //const Rational operator*(const Rational& rhs) const;
    int numerator() const {return n_;}
    int denominator() const {return d_;}
private:
    int n_;
    int d_;

};


const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
} 


int main()
{
    std::cout << "Item24: Declare non-member functions when type conversions should appy to all parameters" << std::endl;

    Rational bob(1, 8);
    Rational simon(1, 2);
    Rational result = bob * simon;
    Rational one_fourth(1, 4);
    result = one_fourth * 2;
    result = 2 * one_fourth;
    return 0;
}
