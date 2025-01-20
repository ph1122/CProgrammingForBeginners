#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int size = 10;
	int* p = malloc(size * sizeof(int));
	printf("%p\n", p);
	for (int i = 0; i < 10; ++i) {
		p[i] = i * 10; // 000001AE658E0400
	}
	size = 100;
	p = realloc(p, size); // 即使变了地址，数据也会拷贝
	printf("%p\n", p);  // 000001AE658E66A0   原来的内存空间后面没有连续的100*sizeof(int)
	for (int i = 0; i < 10; ++i) {
		printf("%d ", p[i]); // 0 10 20 30 40 50 60 70 80 90
	}
	return 0;
}