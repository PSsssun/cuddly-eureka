#include <iostream>
#include <string>

class SpecialString: public std::string{

};

int main()
{
SpecialString* pss = new SpecialString();
std::string* ps;

ps = pss;
delete ps;

}
