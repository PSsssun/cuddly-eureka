#include <iostream>
#include <string>

#include "person_impl.h"

class Person {
public:
    Person(const std::string& name, const Date& birthday, const Address& addr);
    std::string name() const;
    std::string birth_date() const;
    std::string address() const;

private:
    // std::string name_; // implementation detail
    // Date date_; //implemtation detail
    // Address address_; // implementation detail
    std::shared_ptr<PersonImpl> plmpl_ptr_;
};


Person::Person(const std::string& name,
               const Date& birthday,
               const Address& addr) :plmpl_ptr_(new PersonImpl(name, birthday, addr)) {}

std::string Person::birth_date() const {
    return plmpl_ptr_->birth_date();
}

std::string Person::name() const {
    return plmpl_ptr_->name();
}

std::string Person::address() const {
    return plmpl_ptr_->address();
}

int test() {
    std::cout << "Item 31: minimize comilation dependencies between files. \n";
    {
        std::string name("Bob");
        Date birth_day;
        Address addr;
        Person pp(name, birth_day, addr);
        std::cout << pp.name()
            << " was born on "
            << pp.birth_date()
            << " and now lives at "
            << pp.address();
    
    }

    return 0;


}
