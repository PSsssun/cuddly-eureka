#include <iostream>
#include "control_flags.h"

int main(){
    std::cout << std::boolalpha;

    std::cout << "enable_gain_scheduler: " << FLAGS_enable_gain_scheduler << std::endl;
    return 0;


}