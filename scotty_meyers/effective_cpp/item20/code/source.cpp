#include<iostream>

class Person {
public:
    Person():name_(""), address_("") {std::cout << "base contructor" << std::endl;}; //parameters ommitted for simplicity
    virtual ~Person() {std::cout << "base destructor" << std::endl;};
private:
    std::string name_;
    std::string address_;
};



class Student: public Person {
public:
    Student():school_name_(""), school_address_("") {std::cout << "derived contrustor" << std::endl;}; //parameters again ommited
    virtual ~Student() {std::cout << "derived destructor" << std::endl;};

    //bool ValidateSudent(Student s);
    bool ValidateStudent(const Student& s);
private:
    std::string school_name_;
    std::string school_address_;
};

bool Student::ValidateStudent(const Student& s){
    return true;
}


int main() {

    std::cout << "Item 20: Prefer pass-by-reference-to-const to pass-by-value." << std::endl;

    Student bob;
    bob.ValidateStudent(bob);
    return 0;
}




