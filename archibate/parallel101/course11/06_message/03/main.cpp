#include <cstdio>

int main(){
#ifdef MY_NAME
    print("Hello, %s!\n", MY_NAME)
#else
    printf("I don't know your name!\n");
#endif
            
}
