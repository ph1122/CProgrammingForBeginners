#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 10;
    int* pa = &a;
    // ������:  *ָ�������
    printf("*pa = %d\n", *pa); // 10
    a = 11;
    printf("*pa = %d\n", *pa); // 11
    // �޸����ݣ�   *ָ������� = ֵ;
    *pa = 12;
    printf("*pa = %d\n", *pa); // 12
    printf("a = %d\n", a);     // 12
    return 0;
}