#include <iostream>
#include <vector>
#include <memory>


class Window { // base class
public:
    virtual void onResize() {std::cout << "Call Window onResize." << std::endl;}
};

class SpecialWindow: public Window {//derived class
public:
    virtual void onResize() {
        Window::onResize(); 
        std::cout << "SpecialWindow's onResize" << std::endl;
    }

    void blink(const std::string& str) {
        std::cout << "called SpecialWindow blink is by " << str << std::endl; 
    }
};


int main() {
    std::cout << "Item 27: Minimize casting." << std::endl;
    {
        typedef
            std::vector<std::shared_ptr<Window>> VPW;
        VPW winPtrs;
        auto* ptr = new Window();
        winPtrs.emplace_back(ptr);
        for (VPW::iterator iter = winPtrs.begin();
             iter != winPtrs.end();
             ++iter) { 
            (*iter)->onResize();
            if (SpecialWindow* psw = dynamic_cast<SpecialWindow*>(iter->get()))
            {   
            //    psw->onResize();
                psw->blink("Window");
            }
        }
    
    }


    std::cout << "try to do this instead: " << std::endl;
    //try to do this instead:
    {
        typedef 
            std::vector<std::shared_ptr<SpecialWindow>> VPSW;
        VPSW winPtrs;
        auto* ptr = new SpecialWindow();
        winPtrs.emplace_back(ptr);
        for (VPSW::iterator iter = winPtrs.begin();
             iter != winPtrs.end();
             ++iter) {
            (*iter)->onResize();
            (*iter)->blink("SpecialWindow");
        }
    
    }

    return 0;

}
