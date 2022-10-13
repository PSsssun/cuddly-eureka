#include <iostream>

class Uncopyable {
protected: //allow derived class to construct and destruct
        Uncopyable() {}
        ~Uncopyable() {}

private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);

};

class HomeForSale: private Uncopyable {

};



int main()
{
    HomeForSale h1;
    HomeForSale h2;
   // HomeForSale h3(h1);
   // h2 = h1;


    return 0;

}
