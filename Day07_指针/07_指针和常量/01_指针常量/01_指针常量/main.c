#define _CRT_SECURE_NO_WARNIGNS
#include<stdio.h>

// 指针常量是指针本身是常量，指针的地址不能改变。
int main() {
	int a = 10;
	int b = 2;
	// 指针常量
	int* const p = &a;
	// 指针的值是一个常量，也就是说地址不能变，但是指向的变量的值是可以变的
	// p = &b;  左值是个常量，不能被修改
	a = 210;
	printf("%d\n", *p); // 210

	return 0;
}
