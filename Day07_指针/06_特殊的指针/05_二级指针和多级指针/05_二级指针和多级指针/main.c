#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 指针叫做指针变量，它也有地址

int main() {
	// 指向的数据类型 * 指针名;
	// 数据类型 *     * 指针名;
	// int** ppa;

     // 1、定义一个整型变量
    int a = 10;

    // 2、定义一个指向变量a的指针
    int* pa = &a;

    // 3、定义一个指向真正变量pa的指针
    int** ppa = &pa;

    printf("pa    =  %p\n", pa);    // 000000CB4F5AF7C4
    printf("ppa   =  %p\n", ppa);   // 000000CB4F5AF7E8
    printf("*ppa  =  %p\n", *ppa);  // 000000CB4F5AF7C4
    printf("**ppa =  %d\n", **ppa); // 10

    // ppa = && a; && 是逻辑与
    // ppa = &(&a); &a 是一个右值（临时值），不能对它再次取地址。
    // pa = &10;   10 是一个常量，没有内存地址，因此不能对它取地址。
	return 0;
}
