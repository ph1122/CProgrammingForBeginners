#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 指针是个地址  数组名也是一个地址
int main() {
	// 利用指针来访问元素
	int a[] = { 5, 4,3,2,1 };
	printf("数组第0个元素：%d\n", a[0]); // 5

	int* pa = a; // pa的值是数组a的首地址，并不是数组a的地址，虽然值是一样的，但是pa++的结果不一样
	printf("数组第0个元素：%d\n", *pa); // 5

	printf("a      的值：%p\n", a);        // 006FFAC0
	printf("&a[0]  的值：%p\n", &a[0]);    // 006FFAC0
	printf("pa     的值：%p\n", pa);       // 006FFAC0
	printf("&pa[0] 的值：%p\n", &pa[0]);   // 006FFAC0
	printf("*pa    的值：%d\n", *pa);      // 5
	printf("a[0]   的值：%d\n", a[0]);     // 5
	printf("pa[0]  的值：%d\n", pa[0]);    // 5
	printf("------------------------------------------------\n");
										   
	printf("a + 1  的值：%p\n", a + 1);    // 006FFAC4
	printf("&a[1]  的值：%p\n", &a[1]);    // 006FFAC4
	printf("pa + 1 的值：%p\n", pa + 1);   // 006FFAC4
	printf("&pa[1] 的值：%p\n", &pa[1]);   // 006FFAC4
	printf("*(pa+1)的值：%d\n", *(pa + 1));// 4
	printf("a[1]   的值：%d\n", a[1]);     // 4
	printf("pa[1]  的值：%d\n", pa[1]);    // 4
	printf("------------------------------------------------\n");

	printf("a + 2  的值：%p\n", &a[2]);    // 006FFAC8
	printf("&a[2]  的值：%p\n", &a[2]);    // 006FFAC8
	printf("pa + 2 的值：%p\n", pa + 2);   // 006FFAC8
	printf("&pa[2] 的值：%p\n", &pa[2]);   // 006FFAC8
	printf("*(p+2) 的值：%d\n", *(pa + 2));// 3
	printf("a[2]   的值：%d\n", a[2]);     // 3
	printf("pa[2]  的值：%d\n", pa[2]);    // 3
	printf("------------------------------------------------\n");

	//    pa + i == &a[i]
	// *(pa + i) ==  a[i]
	pa++;   // pa = pa + 1;
	printf("*p 的值：%d\n", *pa); // 4
	// a++; 语法错误    数组名是一个常量，不能改变

	return 0;
}
