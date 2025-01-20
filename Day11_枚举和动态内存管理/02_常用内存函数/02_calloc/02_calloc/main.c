#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int size = 10;
	int* p = calloc(size, sizeof(int));

	for (int i = 0; i < size; i++) {
		printf("%d ", p[i]); // 0 0 0 0 0 0 0 0 0 0
	}

	return 0;
}
/*
malloc：

malloc 只分配内存，但不会初始化内存中的内容。

分配的内存中可能包含随机值（即“垃圾值”）。

calloc：

calloc 不仅分配内存，还会将分配的内存初始化为 0。

例如，如果你分配了一个 int 数组，calloc 会将每个元素初始化为 0。

*/