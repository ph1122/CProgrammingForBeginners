#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// ������ַ����
void swap(int* x, int* y)
{
	printf("����ǰ��x��ֵ  ��%p��y��ֵ  ��%p\n", x, y);
	// ����ǰ��x��ֵ  ��00D3FEAC��y��ֵ  ��00D3FEA0
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}
int main() {
	int a = 1, b = 2;
	printf("a = %d, b = %d\n", a, b);// a = 1, b = 2

	printf("����ǰ��a�ĵ�ַ��%p��b�ĵ�ַ��%p\n", &a, &b); // ����ǰ��a�ĵ�ַ��00D3FEAC��b�ĵ�ַ��00D3FEA0
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b); // a = 2, b = 1
	printf("������a�ĵ�ַ��%p��b�ĵ�ַ��%p\n", &a, &b);
	// ������a�ĵ�ַ��00D3FEAC��b�ĵ�ַ��00D3FEA0

	return 0;
}
