#include <stdio.h>
typedef int(*callback)(int, int);

int add(int a, int b, callback p) {
    return (*p)(a, b);
}

int add(int a, int b) {
    return a+b;
}

int main(int argc, char * args[]){
    int res = add(4, 2, add);
    printf("%d\n", res);
    return 0;
}