#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int size = 8;
	int* p = malloc(size * sizeof(int));
	printf("%p\n", p);   // 000002A3BC1C33B0
	for (int i = 0; i < size; ++i) {
		printf("%d\n", p[i]); // -842150451

		*(p + i) = i * size;
	}
	for (int i = 0; i < size; ++i) {
		printf("%d\n", p[i]); // 0 8 16 24 32 ......
		printf("%p\n", &p[i]);
	}
	return 0;
}
