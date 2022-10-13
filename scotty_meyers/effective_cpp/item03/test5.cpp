#include <iostream>
#include <cstring>


class CTextBlock {
public:
    CTextBlock() = default;
    std::size_t length() const;
private:
    char* pText;
    mutable std::size_t textLength;
    mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const {
    if (!lengthIsValid) {
        textLength = std::strlen(pText); //
        lengthIsValid = true;
    }
    return textLength;

}


int main()
{
return 0;
}
