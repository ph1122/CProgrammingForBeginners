#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 悬空指针 指针指向的空间曾经分配过内存，但是现在已经被释放了
int* func()
{
	int a = 56;
	printf("&a = %p\n", &a); // 008FF758
	return &a;
}

int main() {
	int* p = func();
	printf(" p = %p\n", p); // 008FF758
	printf("*p = %d\n", *p); // -858993460 当函数退出的时候，函数内部的变量a的内存会进行释放

	return 0;
}