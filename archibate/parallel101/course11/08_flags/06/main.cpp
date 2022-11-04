#include <cstdio>

int main() {
#ifdef MY_NAME
    printf("Hello, %s!\n", MY_NAME);
#else
    printf("I don't known your name!\n");
#endif


}
