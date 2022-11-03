#include <cstdio>
#ifdef WITH_TBB
#include <tbb/parallel_for.h>
#endif

int main() {
#ifdef WITH_TBB
    tbb::parallel_for(0, 4, [&](int i) {
        printf("hello, parallel_for: %d\n", i);
    });

#else 
    for (int i = 0; i < 4; i++){
//#endif 
        printf("Hello with_not_tbb, %d\n", i);
//#ifdef WITH_TBB
//    });
//#else
    }
#endif

}
