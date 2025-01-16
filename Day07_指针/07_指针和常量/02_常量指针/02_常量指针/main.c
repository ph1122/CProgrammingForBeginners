#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a = 2;
	int b = 10;

	// 常量指针
	// const 数据类型*
	const int* pa = &a;

	// 指向常量的指针
	// 指针所指向地址的值，不能通过指针去改变(解引用)，地址的值是可以改变的
	printf("%d\n", *pa); // 2
	//*pa = 10;  左值指定 const 对象
	pa = &b;
	printf("%d\n", *pa); // 10

	return 0;
}