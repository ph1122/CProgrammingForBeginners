#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
// malloc  calloc  recalloc分配的都是在堆上
int* getarray(int* arr, int size) {
	int* p = malloc(size * sizeof(int));
	if (p == NULL) {
		return NULL;
	}
	for (int i = 0; i < size; ++i) {
		p[i] = arr[i] * arr[i];
	}
	return p;
}
int main() {
	int arr[] = { 1,2,3 };
	int size = sizeof(arr) / sizeof(int);
	int* p = getarray(&arr, size);
	for (int i = 0; i < size; ++i) {
		printf("%d\n", p[i]);
	}
	return 0;
}
