#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 野指针：指针指向的空间未分配内存
// 内存分配 是指程序在运行时从系统中获取一块内存空间，用于存储数据。

int main() {
	int a = 10;
	int* pa = &a;
	printf("*pa = %d\n", *pa); // 10
	printf(" pa = %p\n", pa);  // 000000FBB32FF914

	int* pb = pa + 4; // pb这个地址实际上还没有明确的内存分配
	printf("*pb = %d\n", *pb); // -858993460
	printf(" pb = %p\n", pb);  // 000000FBB32FF924

	return 0;
}