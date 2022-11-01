#include<iostream>
#include<memory>

class Investment {
public:
    Investment() {std::cout << "constructor" << std::endl; }
    ~Investment() {std::cout << "destructor" << std::endl;}
    std::shared_ptr<Investment> CreateInvestment(Investment* p);

    static void GetRidOfInvestment(Investment* ptr) {
       // ptr->~Investment();
        std::cout << "GetRidOfInvestment" << std::endl;
        ptr->~Investment();
    }

};


std::shared_ptr<Investment> Investment::CreateInvestment(Investment* p) {
    if (p == NULL)
    {
        return NULL;
    }
    //std::shared_ptr<Investment> pInv(static_cast<Investment*>(0), Investment::GetRidOfInvestment);
    std::shared_ptr<Investment> pInv(p, Investment::GetRidOfInvestment); 
    std::cout << "CreateInvestment" << std::endl;
    return pInv;

}

int main() {
    std::cout << "Item 18: Make interfaces easy to use correctly and hard to use incorrectly." << std::endl;
    Investment().CreateInvestment(new Investment);
    return 0;

}



