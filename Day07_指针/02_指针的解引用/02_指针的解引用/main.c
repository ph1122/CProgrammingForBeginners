#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 10;
    int* pa = &a;
    // 解引用:  *指针变量名
    printf("*pa = %d\n", *pa); // 10
    a = 11;
    printf("*pa = %d\n", *pa); // 11
    // 修改数据：   *指针变量名 = 值;
    *pa = 12;
    printf("*pa = %d\n", *pa); // 12
    printf("a = %d\n", a);     // 12
    return 0;
}