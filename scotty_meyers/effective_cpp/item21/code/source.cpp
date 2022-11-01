#include<iostream>

class Rational {
public:
    Rational(int numerator = 0, //see Item 24 for why this ctor is not declared explicit
             int denominator = 1) : n_(numerator), d_(denominator) {}
    void Print(const Rational& rhs) const {
        std::cout << "Love is " << rhs.n_ << "/" << rhs.d_ << std::endl;
    }
private:
    int n_, d_;
    friend const Rational operator*(const Rational& lhs,
                                    const Rational& rhs);
};
const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(std::move(lhs.n_ * rhs.n_), std::move(lhs.d_ * rhs.d_));
}

int main() {
    std::cout << "Item 24: Don't try to return a reference when you must return an object." << std::endl;

    Rational bob(2, 5);
    Rational simon(5, 2);

    Rational love = bob * simon;
    love.Print(love);
    
    const Rational c1(2, 5);
    c1.Print(c1);
    return 0;


}
