#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// ����ָ�� ָ��ָ��Ŀռ�����������ڴ棬���������Ѿ����ͷ���
int* func()
{
	int a = 56;
	printf("&a = %p\n", &a); // 008FF758
	return &a;
}

int main() {
	int* p = func();
	printf(" p = %p\n", p); // 008FF758
	printf("*p = %d\n", *p); // -858993460 �������˳���ʱ�򣬺����ڲ��ı���a���ڴ������ͷ�

	return 0;
}