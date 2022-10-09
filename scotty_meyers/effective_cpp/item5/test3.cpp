#include <iostream>
#include <string>

template <class T>
class NamedObject {
public:
    NamedObject(std::string& name, const T& value);// name is a reference to non-const string 
private:
    std::string& nameValue; 
    const T objectValue;
};

template <typename T>
NamedObject<T>::NamedObject(std::string& name, const T& value)
    : nameValue(name),
      objectValue(value)
{

}


int main()
{
    std::string newDog("Persephone");
    std::string oldDog("Satch");
    
    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);

    //p = s; copy assignment operator is implicited deleted.

    return 0;




}
