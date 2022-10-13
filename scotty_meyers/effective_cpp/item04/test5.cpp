#include <iostream>
#include <string>

class ABEntry {
public:
    ABEntry(const std::string& name, const std::string& address)
        : theName(name),
          theAddress(address),
          numTimesConsulted(0)
    {}
private:
    std::string theName;
    std::string theAddress;
    int numTimesConsulted;    

};

int main()
{
    ABEntry abe = ABEntry("he", "qin");
    

    return 0;   
}
