#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a = 2;
	int b = 10;

	// ����ָ��
	// const ��������*
	const int* pa = &a;

	// ָ������ָ��
	// ָ����ָ���ַ��ֵ������ͨ��ָ��ȥ�ı�(������)����ַ��ֵ�ǿ��Ըı��
	printf("%d\n", *pa); // 2
	//*pa = 10;  ��ֵָ�� const ����
	pa = &b;
	printf("%d\n", *pa); // 10

	return 0;
}