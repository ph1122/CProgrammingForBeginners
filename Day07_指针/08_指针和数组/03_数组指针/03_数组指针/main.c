#define _CRT_SECURE_NO_WATNINGS
#include<stdio.h>
// ����ָ����һ��ָ�룬��ָ��һ�����顣
int main() {
	// 1���ȶ���һ������
	int arr[] = { 7, 8,4,2,4 };
	// 2���ٶ���һ������ָ��
	// �������� (*ָ����)[�����С];
	int (*parr)[5] = &arr;// parr��ֵ������ĵ�ַ�������Ǵ��������׵�ַ�ĵ�ַ����Ȼֵ��һ���ģ�����pa++�Ľ����һ��
	// 3����ӡ��ַ
	printf("arr  = %p\n",  arr); // ������Ԫ�صĵ�ַ   000000C3C498F9F8
	printf("parr = %p\n", parr); // ����ĵ�ַ         000000C3C498F9F8
	printf("*parr= %p\n", *parr);// ������Ԫ�صĵ�ַ   000000C3C498F9F8
	// 4������
	int* p = &arr[0];
	printf("arr + 1    = %p\n", p + 1);      // 000000C3C498F9FC  ����4
	printf("parr + 1   = %p\n", parr + 1);	 // 000000C3C498FA0C  ����20��4*5��
	printf("*parr + 1  = %p\n", *parr + 1);	 // 000000C3C498F9FC  ����4
	// 5������ָ�����;
	double d[3][5] = {
		{4, 3, 2, 1, 0},
		{9,8,7,6,5},
		{-1,-2,-3,-4,-5}
	};
	double (*pd)[5] = &d[0];
	for (int i = 0; i < 3; ++i) {
		double (*pdi)[5] = pd + i;
		//double* p = *(pd + i);
		double* p = *pdi;
		for (int j = 0; j < 5; ++j) {
			printf("%.1lf\n", p[j]);
		}
	}

	return 0;
}