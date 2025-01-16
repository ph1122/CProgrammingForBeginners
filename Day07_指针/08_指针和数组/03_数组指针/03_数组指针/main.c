#define _CRT_SECURE_NO_WATNINGS
#include<stdio.h>
// 数组指针是一个指针，它指向一个数组。
int main() {
	// 1、先定义一个数组
	int arr[] = { 7, 8,4,2,4 };
	// 2、再定义一个数组指针
	// 数据类型 (*指针名)[数组大小];
	int (*parr)[5] = &arr;// parr的值是数组的地址，并不是代表数组首地址的地址，虽然值是一样的，但是pa++的结果不一样
	// 3、打印地址
	printf("arr  = %p\n",  arr); // 数组首元素的地址   000000C3C498F9F8
	printf("parr = %p\n", parr); // 数组的地址         000000C3C498F9F8
	printf("*parr= %p\n", *parr);// 数组首元素的地址   000000C3C498F9F8
	// 4、运算
	int* p = &arr[0];
	printf("arr + 1    = %p\n", p + 1);      // 000000C3C498F9FC  加了4
	printf("parr + 1   = %p\n", parr + 1);	 // 000000C3C498FA0C  加了20（4*5）
	printf("*parr + 1  = %p\n", *parr + 1);	 // 000000C3C498F9FC  加了4
	// 5、数组指针的用途
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