#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// �õ������е�Ԫ��
int* get(int a[], int index)
{
	return &a[index];
}

int main() {
	int arr[] = { 9, 8, 7, 6, 5 };
	int* p = get(arr, 2);
	printf("%d\n",*p); // 7
	*p = 99;
	p = get(arr, 2);
	printf("%d\n", *p); // 99

	return 0;
}