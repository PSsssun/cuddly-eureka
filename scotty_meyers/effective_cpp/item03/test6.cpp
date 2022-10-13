#include <iostream>
#include <string>

class TextBlock{
public:
    TextBlock();

    const char& operator[](std::size_t position) const
    {
        return text[position];
    }

    char& operator[](std::size_t position)
    {
        return const_cast<char&>(
            static_cast<const TextBlock&>(*this)
            [position]
            );
    }
private:
    std::string text;
};

int main()
{
    return 0;

}
