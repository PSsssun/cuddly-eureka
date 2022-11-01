#include <iostream>
#include <memory>



/**
  template<typename T,
    std::size_t n>
    class SquareMatrix {
    public:
        template<class D>
        SquareMatrix(D n): n_(n) {}
        void invert(); // invert the matrix in place
    private:
        int n_;
    };

  template<typename T, std::size_t n>
  void SquareMatrix<T, n>::invert() {
    std::cout << "Call SquareMatrix<T, n>::invert " << n_ << " * " << n_ << " size.\n";
  }

  // An alterantive is have SquareMatrixBase store a pointer to the memory for 
  the matrix value 
*/


template <typename T>
class SquareMatrixBase {
protected:
    SquareMatrixBase(std::size_t n, T* pMem)
        : size_(n), data_(pMem) {}
    void SetDataPtr(T* ptr) {data_ = ptr;}
private:
    std::size_t size_;
    T* data_;

};

template <typename T, std::size_t n>
class SquareMatrix :private SquareMatrixBase<T> {
public:
    SquareMatrix() : SquareMatrixBase<T>(n, 0), data_ptr_(new T[n*n]) {
        this->SetDataPtr(data_ptr_.get());
    }
    void invert(); // invert the matrix in place
private:
    std::unique_ptr<T[]> data_ptr_;
};


template<typename T, std::size_t n>
void SquareMatrix<T, n>::invert() {
    std::cout << "Call SquareMatrix<T, n>::invert " << n << " * " << n << " sizes.\n";
}

int main() 
{
    std::cout << "Item 44: Factor parameter-independent code out of templates.\n";

    {
        SquareMatrix<double, 5> sm3;
        sm3.invert();
    }

    return 0;

}
