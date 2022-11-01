#include <iostream>

class FontHandle {
public:
    FontHandle(): font_size_ (0) {}
    ~FontHandle() {}
    void SetFontSize(int fontsize) {
        if (fontsize < 0)
        {
            return;
        }
        font_size_ = fontsize;
    }
private:
    int font_size_;
};


class Font { //RAII class
public:
    explicit Font(FontHandle fh) // acquire resource;
        : f(fh)     // use pass-by-value cos the C API does
    {}
    ~Font() {releaseFont(f);} // release resource // handle coping (see item 14)
    void releaseFont(FontHandle f) {
        f.~FontHandle();
    }
    operator FontHandle() const {
        std::cout << "implicit conversion" << std::endl;
        return f;
    } // implicitly conversion function
    FontHandle get() const 
    {
        std::cout << "explicit conversion" << std::endl;
        return f;
    } // explicit conversion function
    void changeFontSize(FontHandle f, int newSize) {
        f.SetFontSize(newSize);
    }
private:
    FontHandle f; // the raw font resource

};

FontHandle getFont() {
    FontHandle f;
    return f;
}

int main() {
    std::cout << "Item 15: Provide access to raw resources in resource managing classes." << std::endl;

    {
        Font f(getFont());
        int newFontSize = 10;
        f.changeFontSize(f.get(), newFontSize);
    }

    {
        Font f1(getFont());
        FontHandle f2 = f1;
        f1.~Font();
        f2.SetFontSize(12);
    }
    return 0;
    return 0;

}
