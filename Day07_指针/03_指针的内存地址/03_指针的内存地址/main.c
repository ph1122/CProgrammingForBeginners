#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int* p1;
    short* p2;
    char* p3;
    double* p4;
    long long* p5;

    printf("%zu\n", sizeof(p1)); // 8  64位系统中需要8个字节存储
    printf("%zu\n", sizeof(p2)); // 8
    printf("%zu\n", sizeof(p3)); // 8
    printf("%zu\n", sizeof(p4)); // 8
    printf("%zu\n", sizeof(p5)); // 8
    return 0;
}
