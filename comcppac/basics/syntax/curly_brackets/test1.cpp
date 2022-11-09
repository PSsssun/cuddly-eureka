
#include <iostream>

struct TriggerTimestampMs {
    operator double() const {return t;}
    double t{};
};

int main() {
    TriggerTimestampMs t1;
    std::cout << "TriggerTimestampMs t1, double(t1) " << double(t1) << std::endl;
    TriggerTimestampMs t2{};
    std::cout << "TriggerTimestampMs t2{}, double(t2) " << double(t2) << std::endl;
    TriggerTimestampMs t3;
    t3.t = 3;
    std::cout << "TriggerTimestampMs t3, double(t2) " << double(t3) << std::endl;
    return 0;

}