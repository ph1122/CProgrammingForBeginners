#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ָ�����ָ���������Ҳ�е�ַ

int main() {
	// ָ����������� * ָ����;
	// �������� *     * ָ����;
	// int** ppa;

     // 1������һ�����ͱ���
    int a = 10;

    // 2������һ��ָ�����a��ָ��
    int* pa = &a;

    // 3������һ��ָ����������pa��ָ��
    int** ppa = &pa;

    printf("pa    =  %p\n", pa);    // 000000CB4F5AF7C4
    printf("ppa   =  %p\n", ppa);   // 000000CB4F5AF7E8
    printf("*ppa  =  %p\n", *ppa);  // 000000CB4F5AF7C4
    printf("**ppa =  %d\n", **ppa); // 10

    // ppa = && a; && ���߼���
    // ppa = &(&a); &a ��һ����ֵ����ʱֵ�������ܶ����ٴ�ȡ��ַ��
    // pa = &10;   10 ��һ��������û���ڴ��ַ����˲��ܶ���ȡ��ַ��
	return 0;
}
