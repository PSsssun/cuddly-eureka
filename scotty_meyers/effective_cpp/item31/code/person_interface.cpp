#include "person_interface.h"

std::shared_ptr<Person> Person::create(const std::string& name, const Date& birthday, const Address& addr) {
    return std::shared_ptr<Person>(new RealPerson(name, birthday, addr));
}


std::string RealPerson::birth_date() const {
    return birthdate_.birth_day();

}

std::string RealPerson::name() const {
    return name_;
}

                                                    
std::string RealPerson::address() const {
    return address_.address_name();
}


int main() {
    std::cout << "Item 31: minimize compilation dependencies between files." << std::endl;

    {
        std::string name("Bob");
        Date birth_day;
        Address addr;
        std::shared_ptr<Person> pp(Person::create(name, birth_day, addr));
        std::cout << pp->name()
            << " was born on "
            << pp->birth_date()
            << " and now lives at "
            << pp->address();
    
    }

    return 0;



}
