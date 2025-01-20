#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int size = 10;
	int* p = malloc(size * sizeof(int));
	printf("%p\n", p); // 000001B00630F360
	for (int i = 0; i < size; ++i) {
		p[i] = i;
	}
	printf("%d\n", p[0]); // 0

	free(p);   // p现在是悬空指针：指向已经释放或无效内存的指针
	printf("%p\n", p); // 000001B00630F360
	printf("%d\n", p[0]); // 6226029
	p = NULL;
	if (p != NULL) {
		printf("%d\n", p[0]); 
	}

	return 0;
}
