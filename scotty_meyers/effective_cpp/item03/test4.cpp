#include <iostream>

class CTextBlock {
public:
    CTextBlock(char const * p)  
    {char* pText =  const_cast<char*>(p);
     pText = new char[10];}
    char& operator[](std::size_t position) const 
    {return pText[position];} //bitwise const declaration, but inappropriate

private:
    char* pText;

};

int main()
{
    const CTextBlock cctb("Hello"); 
    //char* pc = &cctb[0];
    //*pc = 'J';

    //std::cout << "const" <<  cctb[0] << std::endl;
    return 0;

}
