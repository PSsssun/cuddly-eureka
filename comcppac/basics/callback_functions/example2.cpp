#include <stdio.h>
#include <cstring>
//typedef int (callBack)(const void *buffer, size_t size, char *p_out);
 typedef int (callBack)(const void *buffer, size_t size, char *p_out);

//void callFunc(callBack consume_bytes, char *p_out){
void callFunc(callBack* consume_bytes, char *p_out){
    printf("callFunc\n");
    const void *buffer = NULL;
    consume_bytes(buffer, 0, p_out); //传入值可以随便填
}

int callBackFunc(const void *buffer, size_t size, char *p_out) {
    printf("callBackFunc\n");
    memset(p_out, 0x00, sizeof(char)*100);
    strcpy(p_out, "encoderCallback:this is string.");
    return 1;
}

int main(int argc, char *args[]) {
    char p_out[100];
    callFunc(callBackFunc, p_out);
    printf("%s\n", p_out);
    return 0;
}
