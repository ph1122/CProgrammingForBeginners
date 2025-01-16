#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	// 1、指针和整数的加减法
	int a;
	int* pa = &a;
	printf("pa     = %p\n", pa);     // 000000AB1E0FFB24
	printf("pa + 1 = %p\n", pa + 1); // 000000AB1E0FFB28
	// 对指针进行加法运算，相当于对在内存上往前走了一步，取决于 指针 的数据类型
	// 就是对内存地址的偏移，取决于 指针 的数据类型

	double b;
	double* pb = &b;
	printf("pb     = %p\n", pb);     // 0000000D850FF7A8 A9 AA AB AC AD AE AF
	printf("pb + 1 = %p\n", pb + 1); // 0000000D850FF7B0
	printf("pb - 1 = %p\n", pb - 1); // 0000000D850FF7A0

	// 2、指针在数组上的偏移
	// 数组是一块连续的内存
	int arr[] = { 5, 2, 0, 1, 3, 1, 4 };
	int* parr = &arr[0];
	printf("*parr = %d\n", *parr);             // 5
	printf("*(parr + 1) = %d\n", *(parr + 1)); // 2
	printf("*(parr + 1) = %d\n", *parr + 1);   // 6
	printf("*(parr + 2) = %d\n", *(parr + 2)); // 0
	// 利用指针的加法运算，可以在 数组上快速索引到任意的元素

	printf("parr[3] = %d\n", parr[3]); // 1
	printf("arr[3] = %d\n", arr[3]);   // 1
	// 只要把数组的首地址赋值给指针，
	// 指针就可以进行中括号的操作了

	 // 3、指针和指针之间的减法
	int* pd = &arr[4];
	printf("%lld\n", pd - parr); // 4
	// pd = parr + 4
	// pd - parr = 4
	return 0;
}