#define _CRT_SECURE_NO_WARNIGNS
#include<stdio.h>

// ָ�볣����ָ�뱾���ǳ�����ָ��ĵ�ַ���ܸı䡣
int main() {
	int a = 10;
	int b = 2;
	// ָ�볣��
	int* const p = &a;
	// ָ���ֵ��һ��������Ҳ����˵��ַ���ܱ䣬����ָ��ı�����ֵ�ǿ��Ա��
	// p = &b;  ��ֵ�Ǹ����������ܱ��޸�
	a = 210;
	printf("%d\n", *p); // 210

	return 0;
}
