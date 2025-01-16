#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 指针（变量）  指针 = 内存地址
int main() {
	// 1、指针的定义
	// 数据类型 * 指针变量名;
	int* pa;

	// 2、指针的初始化    指针变量的数据类型要和指向变量的数据类型保持一致
	// 数据类型 * 指针变量名 = &某个变量;   变量存储在内存地址中
	int b  = 1;
	int* pb = &b;   // 取地址符

	double c;
	double* pc = &c;

	char d;
	char* pd = &d;
	// pd = &c;      非法（内存大小不同：ouble 通常占8字节，char 占1字节。如果允许这种赋值，通过 char* 访问 double 数据时，可能会导致内存访问错误或数据截断。）

   // pointer、
   // %p 是 C 语言中 printf 函数的格式说明符，
   // 专门用于打印 指针的值（即指针所指向的内存地址）。
   // 它的作用是以一种可读的格式（通常是十六进制）输出指针的值。
	printf("b的内存地址是：%p\n", pb);// 000000AC44BFFAE4
	// printf("b的内存地址是：%p\n", b);  // 非法
	printf("c的内存地址是：%p\n", pc); // 000000AC44BFFB28
	printf("d的内存地址是：%p\n", pd); // 000000AC44BFFB64

	int arr[] = { 9,8,7,6,5 };  // 数组的内存地址是连续的 
	printf("%p\n", &arr[0]);   // 0000008206EFF8D8   D9 DA DB
	printf("%p\n", &arr[1]);   // 0000008206EFF8DC   DD DE DF
	printf("%p\n", &arr[2]);   // 0000008206EFF8E0   E1 E2 E3
	printf("%p\n", &arr[3]);   // 0000008206EFF8E4
	printf("%p\n", &arr[4]);   // 0000008206EFF8E8

	return 0;
}