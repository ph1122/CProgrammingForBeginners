#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ָ���Ǹ���ַ  ������Ҳ��һ����ַ
int main() {
	// ����ָ��������Ԫ��
	int a[] = { 5, 4,3,2,1 };
	printf("�����0��Ԫ�أ�%d\n", a[0]); // 5

	int* pa = a; // pa��ֵ������a���׵�ַ������������a�ĵ�ַ����Ȼֵ��һ���ģ�����pa++�Ľ����һ��
	printf("�����0��Ԫ�أ�%d\n", *pa); // 5

	printf("a      ��ֵ��%p\n", a);        // 006FFAC0
	printf("&a[0]  ��ֵ��%p\n", &a[0]);    // 006FFAC0
	printf("pa     ��ֵ��%p\n", pa);       // 006FFAC0
	printf("&pa[0] ��ֵ��%p\n", &pa[0]);   // 006FFAC0
	printf("*pa    ��ֵ��%d\n", *pa);      // 5
	printf("a[0]   ��ֵ��%d\n", a[0]);     // 5
	printf("pa[0]  ��ֵ��%d\n", pa[0]);    // 5
	printf("------------------------------------------------\n");
										   
	printf("a + 1  ��ֵ��%p\n", a + 1);    // 006FFAC4
	printf("&a[1]  ��ֵ��%p\n", &a[1]);    // 006FFAC4
	printf("pa + 1 ��ֵ��%p\n", pa + 1);   // 006FFAC4
	printf("&pa[1] ��ֵ��%p\n", &pa[1]);   // 006FFAC4
	printf("*(pa+1)��ֵ��%d\n", *(pa + 1));// 4
	printf("a[1]   ��ֵ��%d\n", a[1]);     // 4
	printf("pa[1]  ��ֵ��%d\n", pa[1]);    // 4
	printf("------------------------------------------------\n");

	printf("a + 2  ��ֵ��%p\n", &a[2]);    // 006FFAC8
	printf("&a[2]  ��ֵ��%p\n", &a[2]);    // 006FFAC8
	printf("pa + 2 ��ֵ��%p\n", pa + 2);   // 006FFAC8
	printf("&pa[2] ��ֵ��%p\n", &pa[2]);   // 006FFAC8
	printf("*(p+2) ��ֵ��%d\n", *(pa + 2));// 3
	printf("a[2]   ��ֵ��%d\n", a[2]);     // 3
	printf("pa[2]  ��ֵ��%d\n", pa[2]);    // 3
	printf("------------------------------------------------\n");

	//    pa + i == &a[i]
	// *(pa + i) ==  a[i]
	pa++;   // pa = pa + 1;
	printf("*p ��ֵ��%d\n", *pa); // 4
	// a++; �﷨����    ��������һ�����������ܸı�

	return 0;
}
