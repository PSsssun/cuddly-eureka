#include <iostream>

class TextBlock {
public:
        TextBlock(std::string _text):text(_text) {}
        const char& operator[](std::size_t position) const 
        {   std::cout << "invoking const" << std::endl;
            return text[position];}
        char& operator[](std::size_t position)
        {   std::cout << "invoking non-const" << std::endl;
            return text[position];}
private:
        std::string text;
};


void print(const TextBlock& ctb)
{
    std::cout << ctb[0];// invoke const TextBlock::operator[]
}

int main()
{
    TextBlock tb("Hello");
    std::cout << tb[0];//invoke non const
    const TextBlock ctb("World");
    std::cout << ctb[0]; // invoke const

    print(ctb);


    return 0;



}
