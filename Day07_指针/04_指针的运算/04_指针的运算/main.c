#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	// 1��ָ��������ļӼ���
	int a;
	int* pa = &a;
	printf("pa     = %p\n", pa);     // 000000AB1E0FFB24
	printf("pa + 1 = %p\n", pa + 1); // 000000AB1E0FFB28
	// ��ָ����мӷ����㣬�൱�ڶ����ڴ�����ǰ����һ����ȡ���� ָ�� ����������
	// ���Ƕ��ڴ��ַ��ƫ�ƣ�ȡ���� ָ�� ����������

	double b;
	double* pb = &b;
	printf("pb     = %p\n", pb);     // 0000000D850FF7A8 A9 AA AB AC AD AE AF
	printf("pb + 1 = %p\n", pb + 1); // 0000000D850FF7B0
	printf("pb - 1 = %p\n", pb - 1); // 0000000D850FF7A0

	// 2��ָ���������ϵ�ƫ��
	// ������һ���������ڴ�
	int arr[] = { 5, 2, 0, 1, 3, 1, 4 };
	int* parr = &arr[0];
	printf("*parr = %d\n", *parr);             // 5
	printf("*(parr + 1) = %d\n", *(parr + 1)); // 2
	printf("*(parr + 1) = %d\n", *parr + 1);   // 6
	printf("*(parr + 2) = %d\n", *(parr + 2)); // 0
	// ����ָ��ļӷ����㣬������ �����Ͽ��������������Ԫ��

	printf("parr[3] = %d\n", parr[3]); // 1
	printf("arr[3] = %d\n", arr[3]);   // 1
	// ֻҪ��������׵�ַ��ֵ��ָ�룬
	// ָ��Ϳ��Խ��������ŵĲ�����

	 // 3��ָ���ָ��֮��ļ���
	int* pd = &arr[4];
	printf("%lld\n", pd - parr); // 4
	// pd = parr + 4
	// pd - parr = 4
	return 0;
}