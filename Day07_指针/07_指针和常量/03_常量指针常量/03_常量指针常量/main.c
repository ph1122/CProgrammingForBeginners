#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a = 1;
	int b = 2;
	// ���� ָ�� ����
	const int* const pa = &a;
	// *pa = 6;    �����ö��޷�����ֵ
    // pa = &b;    ָ���޷�����ֵ

	return 0;
}

/*
ָ�볣��             type* const           ָ���ֵ��һ������            ָ���޷�����ֵ
����ָ��             const type*           ָ������ָ��                ָ��������޷�����ֵ
����ָ�볣��         const type* const     ָ��ֵ��ָ��ֵ���ǳ���        ָ��ͽ����ö��޷�����ֵ
*/