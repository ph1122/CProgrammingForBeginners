#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ָ�����飺һ�����飬�����Ԫ�ض���ָ��
int main() {
	// 1��������������
	int a = 1, b = 2, c = 3;
	// 2������һ��ָ������
	int* parr[3] = { &b, &a, &c };

	// 3����ȡָ��������Ԫ�ص�ֵ
	int* pa = parr[1];
	int* pb = parr[0];
	int* pc = parr[2];

	// 4����ӡ
	printf("*pa=%d,    *pb=%d,   *pc=%d\n", *pa, *pb, *pc);// 1 2 3
	printf("  a=%d,      b=%d,     c=%d\n", a, b, c); // 1 2 3

	// 5��ָ�������ʵ������
	// �Ѷ��ֲ�ͬ���͵ı������洢��һ��������
	int x = 6;
	double y = 7;
	char z = '8';

	void* p[] = { &x, &y, &z };
	char t[] = { 'i', 'f', 'c' };

	return 0;
}