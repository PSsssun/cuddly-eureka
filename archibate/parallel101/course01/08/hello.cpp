#include <cstdio>
#include "hello.h"  // other included files included in hello.h 
// this way makes code simpler and tighter

void hello(MyClass mc){
    printf("Hello, my number is %d!\n", mc.m_number);

}
