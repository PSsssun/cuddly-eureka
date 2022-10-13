#include <iostream>
#include <string>

template <typename T>
class NamedObject{
public:
    NamedObject(const char* name, const T& value);
    NamedObject(const std::string& name, const T& value);

private:
    std::string nameValue;
    T objectValue;
};

template <typename T>
NamedObject<T>::NamedObject(const char* name, const T& value)
    : nameValue(name),
      objectValue(value)
{

}


int main()
{
    NamedObject<int> no1("Smallest Prime Number", 2); 
    NamedObject<int> no2(no1); // invoke copy constructor

    return 0;

}
