#include <iostream>
#include "control_flags.h"

//DEFINE_bool(enable_gain_scheduler, true, "here");

int main(){
    std::cout << std::boolalpha;
    std::cout << "enable_gain_scheduler: " << FLAGS_enable_gain_scheduler << std::endl;
    //if (FLAGS_enable_gain_scheduler) {
    //    std::cout << "Flag is default by on" << std::endl;
    //}

    

    return 0;


}