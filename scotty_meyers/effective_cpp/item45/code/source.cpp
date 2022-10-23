#include <iostream>
class Top {};
class Middle: public Top{};
class Bottom: public Middle {};

template<typename T>
class SmartPtr {
public: //smart pointers are typically
    explicit SmartPtr(T* realPtr);//initialized by built-in pointers
    template<typename U>
    SmartPtr(const SmartPtr<U>& other) :held_ptr_(other.get()){std::cout << "smartptr copy constructor"<<std::endl;}
    T* get() const {return held_ptr_;}
    template<typename U>
    SmartPtr<T>& operator=(const SmartPtr<U>& other);
private:
    T* held_ptr_;
};

template<typename T>
template<typename U>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<U>& other) {
    std::cout << "smartptr (copy assignment) operator =" << std::endl;
    held_ptr_ = other.get();
    return *this;
}


template<typename T>
SmartPtr<T>::SmartPtr(T* realPtr){ 

    std::cout << "explicit smartptr constructor" << std::endl;
    auto p = this->get();
    p = realPtr;
}

int main() 
{
    std::cout << "Item 45: Use member function templates to accept all compatible types.\n";

    {
        Top* pt1 = new Middle; // convert Middle* -> Top*
        Top* pt2 = new Bottom; //convert Bottom* -> Top*
        const Top* pct2 = pt1; //convert Top* -> const Top*

        
    }

    {
        SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle);
        SmartPtr<Top> pt2 = SmartPtr<Bottom>(new Bottom);
        SmartPtr<const Top> pct2 = pt1;
        pct2 = pt1;
    }

    return 0;

}
