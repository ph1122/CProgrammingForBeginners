#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// Ұָ�룺ָ��ָ��Ŀռ�δ�����ڴ�
// �ڴ���� ��ָ����������ʱ��ϵͳ�л�ȡһ���ڴ�ռ䣬���ڴ洢���ݡ�

int main() {
	int a = 10;
	int* pa = &a;
	printf("*pa = %d\n", *pa); // 10
	printf(" pa = %p\n", pa);  // 000000FBB32FF914

	int* pb = pa + 4; // pb�����ַʵ���ϻ�û����ȷ���ڴ����
	printf("*pb = %d\n", *pb); // -858993460
	printf(" pb = %p\n", pb);  // 000000FBB32FF924

	return 0;
}