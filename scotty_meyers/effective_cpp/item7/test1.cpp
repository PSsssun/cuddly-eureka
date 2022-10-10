#include <iostream>

class TimeKeeper {
public:
    TimeKeeper();
    ~TimeKeeper();


};

class AtomicClock: public TimeKeeper {};
class WaterClock: public TimeKeeper {};
class WristClock: public TimeKeeper {};

int main()
{

}
