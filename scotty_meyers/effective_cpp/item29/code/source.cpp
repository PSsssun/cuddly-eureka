#include <iostream>
#include <mutex>
#include <memory>
#include <fstream>
#include <string>
#include <sstream>

class Uncopyable {
public:
    Uncopyable() {}
    ~Uncopyable() {}
    Uncopyable(const Uncopyable&) = delete;
    Uncopyable& operator=(const Uncopyable&) = delete;
private:
    /**
      Uncopyable(const Uncopyable&);
      Uncopyable& operator=(const Uncopyable&);
      **/
};

template <typename T>
struct LockDeleter {
    void operator()(T const* p)
    {
        p->unlock();
    }
};

class Lock:private Uncopyable {
public:
    explicit Lock(std::mutex* pm) : mutex_ptr_(pm, unlock){
        mutex_ptr_.get()->lock();
    }
    //~Lock() {mutex_ptr_->unlock();}
    ~Lock() {}
    static void unlock(std::mutex* p) {
        if (p == NULL)
        {
            return;
        }
        p->unlock();
    }

private:
    std::shared_ptr<std::mutex> mutex_ptr_;
};

class Image {
public:
    Image(std::istream& img_src){
        std::string s;
        while (img_src >> s){
            std::cout << s << std::endl;
        }
    }

private:
};

struct PMImpl {
    std::shared_ptr<Image> ImagePtr;
    int ImageChanges;
};

class PrettyMenu {
 public:
     PrettyMenu(PMImpl *ptr):mutex_(), pmlmpl_ptr_(ptr){}
     void ChangeBackground(std::istream& imgSrc);
private:
     std::mutex mutex_; //mutex for this object
     //std::shared_ptr<Image> bgImage_; // current background image
     //int image_changes_; // # of times image has been changed
     std::shared_ptr<PMImpl> pmlmpl_ptr_;
};

void PrettyMenu::ChangeBackground(std::istream& imgSrc)
{
    using std::swap;
    Lock m1(&mutex_);
    std::shared_ptr<PMImpl> pNew(new PMImpl(*pmlmpl_ptr_));

    pNew->ImagePtr.reset(new Image(imgSrc));

    swap(pmlmpl_ptr_, pNew);


}


int main()
{
    std::cout << "Item 29: Strive for exception-safe code." << std::endl;
    PMImpl* p = new PMImpl();
    PrettyMenu menu(p);

    std::string line;
    std::getline(std::cin, line);
    std::istringstream istr(line);
    menu.ChangeBackground(istr);
    return 0;

}
