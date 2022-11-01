#include <iostream>
#include <memory>

class Investment {
public:
    Investment() {}
    virtual ~Investment() {}
    static Investment *CreateInvestment(int type);
    virtual void Print() = 0;
};

class BobInvestment : public Investment {
public:
    BobInvestment() {}
    ~BobInvestment() {}
    void AddBobInvestment(const int n) {money_ += n;}
    void Print() {std::cout << "Bob's money: " << money_ << ".00" << std::endl;}

private:
    static int money_;

};

int BobInvestment::money_;

Investment *Investment::CreateInvestment(int type) {
    switch(type) {
    case 1:
        return new BobInvestment;
    default:
        break;
    }
    return nullptr;
}

int main() {
    std::cout << "Item 13: Use objects to manage resources." << std::endl;

    /*
       auto pInv = std::make_shared<Investment>();
       std::cout << "size: " << sizeof(pInv) << std::endl; //Do you know why the size is 16 bytes on 64bit system.
       auto p = (BobInvestment *)pInv->CreateInvestment(1);
       p->AddBobInvestment(100);
       delete p;
       */

    {
        std::auto_ptr<BobInvestment> pInv1(
            (BobInvestment *)Investment::CreateInvestment(1));
        std::cout << "pInv1 point to: " << pInv1.get() << std::endl;
        std::auto_ptr<BobInvestment> pInv2(pInv1);
        std::cout << "pInv1 point to: " << pInv1.get()
            << std::endl;
        std::cout << "pInv2 point to: " << pInv2.get() << std::endl;
        pInv2->AddBobInvestment(1000000);
        pInv1 = pInv2;
        std::cout << "pInv2 point to: " << pInv2.get() << std::endl;
        std::cout << "pInv1 point to: " << pInv1.get() << std::endl;

    }

    {
        std::shared_ptr<BobInvestment> pInv3(
            (BobInvestment *)Investment::CreateInvestment(1));
        std::cout << "shared_ptr pInv3 point to: " << pInv3.get() << std::endl;
        std::shared_ptr<BobInvestment> pInv4(pInv3);
        std::cout << "shared_ptr pInv3 point to: " << pInv3.get() << std::endl;
        pInv4->AddBobInvestment(100000);
        pInv4->Print();
        std::cout << "shared_ptr pInv4 point to: " << pInv4.get() << std::endl;
    
    }

    {
        std::cout << "test base pointer and derived pointer" << std::endl;
        std::shared_ptr<BobInvestment> pInv5(
        (BobInvestment *) Investment::CreateInvestment(1));
        std::cout << "pInv5 point to: " << pInv5.get() << std::endl;


    
    }
    return 0;

}
