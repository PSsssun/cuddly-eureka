#include <iostream>

class IntCell{
public:
    explicit IntCell(int x = 0) : storedValue(x)
    {} 
    //IntCell();
    int read() const {return storedValue;}
    void write(int x) { storedValue = x;}
private:
    int storedValue;

};


int main()
{
    std::cout << "1.5.1 Pointers" << std::endl;
    
    IntCell *m;// uninitalized pointer is dangerous

    m = new IntCell{0};
    
    m->write(5);
    std::cout << "Cell contents: " << m->read() << std::endl;

    delete m;

    {
        std::cout << "Dynamic Object Creation" << std::endl;
        IntCell* m1;
        m1  = new IntCell(); //ok
        IntCell* m2;
        m2  = new IntCell{}; //c++11
        IntCell* m3;
        m3  = new IntCell; //Preferred in this text
        
        delete m1;
        delete m2;
        delete m3;
   
    }

    return 0;    


}
