#include <iostream>
#include <mutex>
#include <memory>

class Uncopyable {
public:
    Uncopyable() {}
    ~Uncopyable() {}
    Uncopyable(const Uncopyable&) = delete;
    Uncopyable& operator=(const Uncopyable&) = delete;
private:
    /*Uncopyable (const Uncopyable&);
      Uncopyable& operator=(const Uncopyable&); */
};

template <typename T> 
struct LockDeleter {
    void operator()(T const* p) {p->unlock();}
};


class Lock :private Uncopyable {
public:
    explicit Lock(std::mutex* pm) : mutex_ptr_(pm, unlock) {
    mutex_ptr_.get()->lock();
    }
   // ~Lock() {}
    static void unlock(std::mutex* p) {  //! why static ? and deleter function?
        if (p == NULL)
        {
            return;
        }
        p->unlock();
    }
private:
    // std::mutex *mutex_ptr_;
    std::shared_ptr<std::mutex> mutex_ptr_; //use shared_ptr instead of raw pointer
    
};

int main()
{
    std::cout << "Item 14: Think carefully about copying behavior in resource managing classes." << std::endl;

    {
        std::mutex m; // sizeof(m) = 80
        Lock bob(&m);

    }

    return 0;

}
